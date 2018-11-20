#include <stdio.h>
#include <string.h>
#include <include/object/Process.h>
#include <vm/page/include/object/VMModel.h>
#include <vm/page/module/mmu/mmu.h>
#include <include/define/constant.h>
#include <vm/page/include/object/PCB.h>
#include <module/system/system.h>
#include <vm/page/include/object/VirtualAddress.h>
#include <include/define/color.h>


static int pmu_assign_to_node_pointer(ProcessLinkedNode *node_pointer, Process process,VMModel *vm_model_pointer);

// 创建新的进程
Process pmu_new_process(Process process , VMModel *vm_model_pointer){

	// 生成一个新的进程链结点
	ProcessLinkedNode *node_pointer = mmu_alloc_process_linked_node();
	int process_count = pmu_assign_to_node_pointer(node_pointer,process,vm_model_pointer);

	// 把这个新建的进程链结点记录到 PCB 中
	vm_model_pointer->pcb.process_count = process_count; // process_count赋给PCB中的进程个数
	if(vm_model_pointer->pcb.process_count<2){ // 当前新建的进程链结点是第 1 个结点

		vm_model_pointer->pcb.head = node_pointer; // 赋给PCB中的头指针
	} else { // 当前新建的进程链结点是第 2+ 个结点

		vm_model_pointer->pcb.tail->next = node_pointer; // 把新的进程链结点连接到PCB的尾指针指向的下一个结点
	}
	vm_model_pointer->pcb.tail = node_pointer; // 赋给PCB中的尾指针


	// 想想还有哪里需要记录 ...

	return process;
}

// 中止进程
int pmu_halt_process(Process process,VMModel *vm_model_pointer){

	// 移除此进程在 PCB 中的进程链结点数据
	ProcessLinkedNode *pre = NULL;
	ProcessLinkedNode *p = vm_model_pointer->pcb.head;
	while( NULL != p && p->process_id != process.process_id ){

		pre = p;
		p = p->next;
	}

	// 如果找到了此进程链结点
	if(NULL!=p&& p->process_id == process.process_id){

		if(NULL == pre){ // 如果当前只有1个进程

			vm_model_pointer->pcb.head=NULL;
			vm_model_pointer->pcb.tail=NULL;

		} else {

			// 上一个结点连向即将移除的结点的下一个结点
			pre->next=p->next;
		}

		// 释放掉所占内存
		mmu_collec_process_linked_node(p);

		// PCB中的进程数 -1
		(vm_model_pointer->pcb.process_count)--;

		// 想想还有哪里需要记录 ...

		return 0;
	}

	// 进程不存在
	system_console_set_color(2);
	printf("Sorry, this process is not exist.\n");
	system_console_set_color(15);
	return 1;
}

// 打印所有的进程
void pmu_print_all_processes(VMModel *vm_model_pointer){

	int i=0;
	ProcessLinkedNode *p = vm_model_pointer->pcb.head;

	if(vm_model_pointer->pcb.process_count<1){

		// 输出提示信息 : 没有任何进程
		system_console_set_color(2);
		printf("Sorry, there is no any processes.\n");
		system_console_set_color(15);
		return;
	}

	// 输出页表
	system_console_set_color(2);
	printf("--------------------------------------------------------------\n");
	printf("| The total process count is : %d\n",vm_model_pointer->pcb.process_count);
	printf("--------------------------------------------------------------\n");
	printf("|              |  Id   |   Name  | virtual_page_number | offset\n");
	while(NULL!=p){ // 这样写的好处是防止写成赋值号，而且更突出重点

		++i;
		printf("--------------------------------------------------------------\n");
		printf("| %dth process  |   %d   |   %s   |           %d         | %d\n",i,p->process_id, p->process_name,p->virtual_address.virtual_page_number,p->virtual_address.offset);
		p = p->next;
	}
	printf("--------------------------------------------------------------\n");
	system_console_set_color(15);


}

// 进程管理单元释放内存
VMModel* pmu_free(VMModel *vm_model_pointer){

	// 释放掉全部的 ProcessLinkedNode 结点
	ProcessLinkedNode *p = vm_model_pointer->pcb.head;
	ProcessLinkedNode *q = NULL;
	while(NULL != p){

		q = p->next;
		mmu_collec_process_linked_node(p);
		p = q;
	}

	// 想想还需要清理什么 ...

	return vm_model_pointer;
}



// 返回进程的个数
static int pmu_assign_to_node_pointer(ProcessLinkedNode *node_pointer, Process process,VMModel *vm_model_pointer){

	int process_count = (vm_model_pointer->pcb.process_count)+1; // PCB中的进程个数+1

	// 进程的相关信息
	node_pointer->process_id = process_count; // 进程 id 是从 1 开始的，最小的进程 id 就是1
	strcpy(node_pointer->process_name,process.process_name);
	strcpy(node_pointer->process_extra,"");

	// 进程的虚拟地址
	node_pointer->virtual_address.virtual_page_number=process_count;//虚页号 : 即为当前的进程个数
	node_pointer->virtual_address.offset = process_count % MEMORY_PAGE_SIZE; // 偏移量 : 即为当前的进程个数 Mod MEMORY_PAGE_SIZE


	// 指向下一个进程链结点的指针
	node_pointer->next=NULL;

	return process_count;
}

