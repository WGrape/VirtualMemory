// 内存中只存放 int 数据( process_id )

// 分配内存
int* mmu_alloc_memory(){

	return (int*)malloc(sizeof(int)*1000);
}

// 收回内存
void mmu_collec_memory(int *p){

	free(p);
}

// 分配 ProcessLinkedNode
int* mmu_alloc_process_linked_node(){

	return (ProcessLinkedNode*)malloc(sizeof(ProcessLinkedNode)*1);	
}

// 载入一个进程
void mmu_load_process(Process process,VMModel vm_model){

	// 进程载入内存中
}

// 移载一个进程
void mmu_unload_process(Process process,VMModel vm_model){

	// 从内存中移除
}

