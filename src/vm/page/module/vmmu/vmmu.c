
// 注册一个新的进程
Process vmmu_register_process(Process process){

	return process;
}


// 虚拟地址到实地址的
PhysicalAddress vmmu_physical_address(VirtualAddress virtualAddress){

	// 根据虚拟地址的虚页号找到在虚页表中存的实页号，实页号和页内地址就构成了实地址
	PageTable pageTable

}
