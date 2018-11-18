
// 注册一个新的进程
Process vmmu_register_process(Process process,VMModel *vm_model_pointer){

	// 创建一个新的页表项结点
	PageTableItemLinkedNode *node = mmu_alloc_page_table_item_linked_node(); // 分配一个页表项结点空间内存
	int page_table_item_count = (vm_model_pointer->page_table.page_table_item_count)+1; // 页表中的页表项个数+1
	*node = {

		virtual_page_number: page_table_item_count, // 虚页号
		physical_page_number: (page_table_item_count/MEMORY_PAGE_SIZE)+1 // 实页号
		load:1,
		next:NULL
	};

	// 把这个新建的页表项加到页表中
	if(vm_model_pointer->page_table.page_table_item_count<2){ // 当前的页表项为空

		vm_model_pointer->page_table.head = node; // 赋给页表中的头指针
	}
	vm_model_pointer->page_table.tail.next = node; // 把新的页表项结点连接到页表的尾指针指向的下一个结点
	vm_model_pointer->page_table.tail = node; // 赋给页表中的尾指针

	// 想想还有哪里需要记录 ...

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

