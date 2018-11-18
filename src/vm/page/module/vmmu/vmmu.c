
// 注册一个新的进程
Process vmmu_register_process(Process process,VMModel *vm_model_pointer){

	// 记录此进程在页表中数据
	PageTableItemLinkedNode *node = mmu_alloc_page_table_item_linked_node(); // 分配一个页表项结点空间内存
	if(vm_model_pointer->page_table.page_table_item_count<1){ // 当前的页表项为空

		vm_model_pointer->page_table.head = node; // 赋给页表中的头指针
	}
	vm_model_pointer->page_table.tail.next = node; // 赋给页表中的尾指针
	(vm_model_pointer->page_table.page_table_item_count)++; // 进程数+1

	// 记录此进程在页表项中的数据
	*node = {

		virtual_page_number:
		physical_page_number:
		load:1
	};

	return process;
}

// 注销一个进程
Process vmmu_unregister_process(Process process,VMModel *vm_model_pointer){

	// 注销记录在页表中的此进程的数据
	
	return process;
}


// 虚拟存储器管理单元释放内存
VMModel* vmmu_free(VMModel *vm_model_pointer){


}

