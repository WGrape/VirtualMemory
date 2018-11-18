// 内存中只存放 int 数据( process_id )



// 载入一个进程
Process mmu_load_process(Process process,VMModel *vm_model_pointer){

	// 进程载入内存中
	int process_count = vm_model_pointer->pcb.process_count; // 获取PCB中当前的进程个数
	*(vm_model_pointer->memory->next) = process.process_id;
	(vm_model_pointer->memory->next)++;

	// 想想还有哪里需要记录 ...

	return process;
}

// 移载一个进程
Process mmu_unload_process(Process process,VMModel *vm_model_pointer){

	// 进程从内存中移除
}





// 分配内存
int* mmu_alloc_memory(){

	int *p = (int*)malloc(sizeof(int)*1000);
	if(!p){

		exit(1);
	}

	return p;
}

// 收回内存
void mmu_collec_memory(int *p){

	free(p);
}

// 分配 ProcessLinkedNode
ProcessLinkedNode* mmu_alloc_process_linked_node(){

	ProcessLinkedNode *p = (ProcessLinkedNode*)malloc(sizeof(ProcessLinkedNode)*1);	
	if(!p){

		exit(1);
	}

	return p;
}

// 回收 ProcessLinkedNode
void mmu_collec_process_linked_node(ProcessLinkedNode *p){

	free(p);
}

// 分配 PageTableItemLinkedNode
PageTableItemLinkedNode* mmu_alloc_page_table_item_linked_node(){

	PageTableItemLinkedNode *p = (PageTableItemLinkedNode*)malloc(sizeof(PageTableItemLinkedNode)*1);	
	if(!p){

		exit(1);
	}

	return p;
}

// 回收 PageTableItemLinkedNode
void mmu_collec_page_table_item_linked_node(PageTableItemLinkedNode *p){

	free(p);
}


