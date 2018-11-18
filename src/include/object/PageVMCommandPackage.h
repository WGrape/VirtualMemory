#ifndef INCLUDE_OBJECT_PAGE_VM_COMMAND_PACKAGE_H
#define INCLUDE_OBJECT_PAGE_VM_COMMAND_PACKAGE_H


typedef struct{

	int vm_type; // 当前的 虚拟存储器 类型

	Memory memory; // 当前的内存
	
	PCB pcb; // PCB块
	
	PageTable page_table; // 页表

}PageVMCommandPackage;


#endif

