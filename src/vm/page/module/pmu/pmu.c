#include <stdio.h>

// 创建新的进程
Process pmu_new_process(Process process,VMModel vm_model){

	// 记录到 PCB 中
	ProcessLinkedNode *p = mmu_alloc_process_linked_node();
	vm_model.pcb.tail.p = p;
	*p = {

		process_id:vm_model.pcb.process_count+1,
		process_name: process.name,
	};

	// 想想还有哪里需要记录 ...

	return process;
}

// 销毁进程
Process pmu_halt_process(Process process,VMModel vm_model){

	// 移除存储在 PCB 中的数据

	return process;
}

// 打印所有的进程
void pmu_print_all_processes(PCB pcb){

	int i=0;
	ProcessLinkedNode *p = pcb->head;
	
	printf("The total process count is : %d , now print the all process below\n",pcb->count);
	while(NULL!=p){ // 这样写的好处是防止写成赋值号，而且更突出重点

		++i;
		printf("%dth process , id: %d , name: %s \n"i,p->process_id, p->process_name);
		p = p->p;
	}
	printf("-----------------END-----------------\n");
	
}

// 进程管理单元释放内存
VMModel pmu_free(VMModel vm_model){

	// 释放掉全部的 ProcessLinkedNode 结点
	ProcessLinkedNode *p = vm_model.pcb.head;
	ProcessLinkedNode *q = NULL;
	while(NULL != p){

		q = p->next;
		free(p);
		p = q;
	}

	// 想想还需要清理什么 ...

	return vm_model;
}