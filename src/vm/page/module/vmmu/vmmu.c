#include <stdlib.h>
#include <include/object/Process.h>
#include <module/system/system.h>
#include <vm/page/include/object/VMModel.h>
#include <vm/page/module/mmu/mmu.h>
#include <include/define/constant.h>

static int vmmu_assign_to_node_pointer(PageTableItemLinkedNode *node_pointer, Process process,VMModel *vm_model_pointer);

// 注册一个新的进程到页表中
Process vmmu_register_process(Process process,VMModel *vm_model_pointer){

	// 创建一个新的页表项结点
	PageTableItemLinkedNode *node_pointer = mmu_alloc_page_table_item_linked_node(); // 分配一个页表项结点空间内存
	int page_table_item_count = vmmu_assign_to_node_pointer(node_pointer,process,vm_model_pointer);


	// 把这个新建的页表项加到页表中
	vm_model_pointer->page_table.page_table_item_count = page_table_item_count; // page_table_item_count赋给页表中的页表项个数
	if(vm_model_pointer->page_table.page_table_item_count<2){ // 当前新建的页表项结点是第 1 个结点

		vm_model_pointer->page_table.head = node_pointer; // 赋给页表中的头指针
	} else { // 当前新建的页表项结点是第 2+ 个结点

		vm_model_pointer->page_table.tail->next = node_pointer; // 把新的页表项结点连接到页表的尾指针指向的下一个结点
	}
	vm_model_pointer->page_table.tail = node_pointer; // 赋给页表中的尾指针

	// 想想还有哪里需要记录 ...

	return process;
}

// 把页表中的一个进程注销掉
Process vmmu_unregister_process(Process process,VMModel *vm_model_pointer){

	// 注销记录在页表中的此进程的数据
	PageTableItemLinkedNode *pre = NULL;
	PageTableItemLinkedNode *p = vm_model_pointer->page_table.head;
	while( NULL != p && p->virtual_page_number != process.process_id ){

		pre = p;
		p = p->next;
	}

	// 如果找到了此页表项结点
	if(NULL!=p && p->virtual_page_number == process.process_id ){

		if(NULL == pre){ // 如果当前只有1个页表项

			vm_model_pointer->page_table.head=NULL;
			vm_model_pointer->page_table.tail=NULL;

		} else {

			// 上一个结点连向即将移除的结点的下一个结点
			pre->next=p->next;
		}

		// 释放掉所占内存
		mmu_collec_page_table_item_linked_node(p);

		// PCB中的进程数 -1
		(vm_model_pointer->pcb.process_count)--;
	}


	// 想想还有哪里需要记录 ...

	return process;
}


// 打印所有的页表项
void vmmu_print_all_page_table_items(VMModel *vm_model_pointer){

	int i=0;
	PageTableItemLinkedNode *p = vm_model_pointer->page_table.head;


	if(vm_model_pointer->page_table.page_table_item_count<1){

		// 输出提示信息 : 没有任何页表项
		system_console_set_color(2);
		printf("Sorry, there is no any items.\n");
		system_console_set_color(15);
		return;
	}

	// 输出页表
	system_console_set_color(2);
	printf("-----------------------------------------------------------------------\n");
	printf("| The total item count is : %d\n",vm_model_pointer->page_table.page_table_item_count);
	printf("-----------------------------------------------------------------------\n");
	printf("|           | virtual_page_number | physical_page_number | load | next  \n");
	while(NULL!=p){ // 这样写的好处是防止写成赋值号，而且更突出重点

		++i;
		printf("-----------------------------------------------------------------------\n");
		printf("| %dth item  |          %d          |           %d          |  %d   | %p \n",i,p->virtual_page_number, p->physical_page_number,p->load,p->next);
		p = p->next;
	}
	printf("-----------------------------------------------------------------------\n");
	system_console_set_color(15);


}


// 虚拟存储器管理单元释放内存
VMModel* vmmu_free(VMModel *vm_model_pointer){

	// 释放掉全部的 PageTableItemLinkedNode 结点
	PageTableItemLinkedNode *p = vm_model_pointer->page_table.head;
	PageTableItemLinkedNode *q = NULL;
	while(NULL != p){

		q = p->next;
		mmu_collec_page_table_item_linked_node(p);
		p = q;
	}

	// 想想还需要清理什么 ...

	return vm_model_pointer;
}


// 返回页表项的个数
static int vmmu_assign_to_node_pointer(PageTableItemLinkedNode *node_pointer, Process process,VMModel *vm_model_pointer){

	int page_table_item_count = (vm_model_pointer->page_table.page_table_item_count)+1; // 页表中的页表项个数+1

	// 进程的在页表项中的相关信息
	node_pointer->virtual_page_number = page_table_item_count; // 虚页号
	node_pointer->physical_page_number = (page_table_item_count/MEMORY_PAGE_SIZE)+1; // 实页号
	node_pointer->load = 1;

	// 指向下一个页表项结点的指针
	node_pointer->next=NULL;

	return page_table_item_count;
}

