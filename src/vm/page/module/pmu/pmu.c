#include <stdio.h>

// 创建新的进程
Process pmu_new_process(Process process,VMModel *vm_model_pointer){

	// 记录到 PCB 中
	ProcessLinkedNode *p = mmu_alloc_process_linked_node();
	vm_model_pointer->pcb.tail.p = p;
	*p = {

		process_id:vm_model_pointer->pcb.process_count+1,
		process_name: process.name,
	};

	// 想想还有哪里需要记录 ...

	return process;
}

// 中止进程
Process pmu_halt_process(Process process,VMModel *vm_model_pointer){

	// 移除存储在 PCB 中的数据
	ProcessLinkedNode *p = vm_model_pointer->pcb.head;
	while(p->process_id != process.process_id){

		p = p->next;
	}

	// 释放掉所占内存
	if(p!=vm_model_pointer->pcb.head){

		mmu_collec_process_linked_node(p);
	}

	return process;
}

// 打印所有的进程
void pmu_print_all_processes(VMModel *vm_model_pointer){

	int i=0;
	ProcessLinkedNode *p = vm_model_pointer->pcb->head;
	
	printf("The total process count is : %d , now print the all process below\n",pcb->count);
	while(NULL!=p){ // 这样写的好处是防止写成赋值号，而且更突出重点

		++i;
		printf("%dth process , id: %d , name: %s \n"i,p->process_id, p->process_name);
		p = p->p;
	}
	printf("-----------------END-----------------\n");
	
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