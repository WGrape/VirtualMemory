
// 注册一个新的进程
Process vmmu_register_process(Process process,VMModel vm_model){

	// 记录此进程的数据到页表中
	ProcessLinkedNode *p = mmu_alloc_process_linked_node();
	vm_model.pcb.tail.p = p;
	*p = {

		process_id:vm_model.pcb.process_count+1,
		process_name: process.name,
	};

	return process;
}

// 注销一个进程
Process vmmu_unregister_process(Process process,VMModel vm_model){

	// 注销记录在页表中的此进程的数据
	
	return process;
}


// 虚拟存储器管理单元释放内存
VMModel vmmu_free(VMModel vm_model){

}

