#include <stdlib.h>
#include <include/object/Process.h>
#include <module/system/system.h>
#include <vm/segment/include/object/SegmentVMModel.h>
#include <vm/segment/module/mmu/mmu.h>
#include <include/define/constant.h>
#include <vm/segment/include/object/SegmentTableItemLinkedNode.h>


static int
segment_vmmu_assign_to_node_pointer(SegmentTableItemLinkedNode *node_pointer, Process process, SegmentVMModel *vm_model_pointer);

// 注册一个新的进程到段表中
Process segment_vmmu_register_process(Process process, SegmentVMModel *vm_model_pointer) {

    // 创建一个新的段表项结点
    SegmentTableItemLinkedNode *node_pointer = segment_mmu_alloc_segment_table_item_linked_node(); // 分配一个段表项结点空间内存
    int segment_table_item_count = segment_vmmu_assign_to_node_pointer(node_pointer, process, vm_model_pointer);


    // 把这个新建的段表项加到段表中
    vm_model_pointer->segment_table.segment_table_item_count = segment_table_item_count; // segment_table_item_count赋给段表中的段表项个数
    if (vm_model_pointer->segment_table.segment_table_item_count < 2) { // 当前新建的段表项结点是第 1 个结点

        vm_model_pointer->segment_table.head = node_pointer; // 赋给段表中的头指针
    } else { // 当前新建的段表项结点是第 2+ 个结点

        vm_model_pointer->segment_table.tail->next = node_pointer; // 把新的段表项结点连接到段表的尾指针指向的下一个结点
    }
    vm_model_pointer->segment_table.tail = node_pointer; // 赋给段表中的尾指针

    // 想想还有哪里需要记录 ...

    return process;
}

// 把段表中的一个进程注销掉
Process segment_vmmu_unregister_process(Process process, SegmentVMModel *vm_model_pointer) {

    // 注销记录在段表中的此进程的数据
    SegmentTableItemLinkedNode *pre = NULL;
    SegmentTableItemLinkedNode *p = vm_model_pointer->segment_table.head;
    while (NULL != p && p->segment_number != process.process_id) {

        pre = p;
        p = p->next;
    }

    // 如果找到了此段表项结点
    if (NULL != p && p->segment_number == process.process_id) {

        if (NULL == pre) { // 如果当前只有1个段表项

            vm_model_pointer->segment_table.head = NULL;
            vm_model_pointer->segment_table.tail = NULL;

        } else {

            // 上一个结点连向即将移除的结点的下一个结点
            pre->next = p->next;
        }

        // 释放掉所占内存
        segment_mmu_collec_segment_table_item_linked_node(p);

        // PCB中的进程数 -1
        (vm_model_pointer->pcb.process_count)--;
    }


    // 想想还有哪里需要记录 ...

    return process;
}


// 打印所有的段表项
void segment_vmmu_print_all_segment_table_items(SegmentVMModel *vm_model_pointer) {

    int i = 0;
    SegmentTableItemLinkedNode *p = vm_model_pointer->segment_table.head;


    if (vm_model_pointer->segment_table.segment_table_item_count < 1) {

        // 输出提示信息 : 没有任何段表项
        system_console_set_color(2);
        printf("Sorry, there is no any items.\n");
        system_console_set_color(15);
        return;
    }

    // 输出段表
    system_console_set_color(2);
    printf("-----------------------------------------------------------------------\n");
    printf("| The total item count is : %d\n", vm_model_pointer->segment_table.segment_table_item_count);
    printf("-----------------------------------------------------------------------\n");
    printf("|           | segment_number | segment_address | segment_length | load | next\n");
    while (NULL != p) { // 这样写的好处是防止写成赋值号，而且更突出重点

        ++i;
        printf("-----------------------------------------------------------------------\n");
        printf("| %dth item  |        %d        |     %p    |      %d      |  %d   | %p\n", i, p->segment_number,
               p->segment_address, p->segment_length, p->load, p->next);
        p = p->next;
    }
    printf("-----------------------------------------------------------------------\n");
    system_console_set_color(15);


}


// 虚拟存储器管理单元释放内存
SegmentVMModel *segment_vmmu_free(SegmentVMModel *vm_model_pointer) {


}


// 返回段表项的个数
static int
segment_vmmu_assign_to_node_pointer(SegmentTableItemLinkedNode *node_pointer, Process process, SegmentVMModel *vm_model_pointer) {

    int segment_table_item_count = (vm_model_pointer->segment_table.segment_table_item_count) + 1; // 段表中的段表项个数+1

    // 进程的在段表项中的相关信息
    node_pointer->segment_number = segment_table_item_count; // 段号
    node_pointer->segment_address = (vm_model_pointer->memory.pr)+(segment_table_item_count-1);
    node_pointer->segment_length = 4;
    node_pointer->load = 1;

    // 指向下一个段表项结点的指针
    node_pointer->next = NULL;

    return segment_table_item_count;
}

