#include<stdio.h>

// 启动页式虚拟存储器
void page_virtual_memory_init(){

	PCB pcb = {NULL};

	// 打印页式存储器的欢迎语
	ui_print_vm_welcome(VM_TYPE_SEGMENT_PAGE);

	while(RES_OK == command_enter_interactive_env(VM_TYPE_SEGMENT_PAGE)){

		ui_print_vm_menu();
	}

}