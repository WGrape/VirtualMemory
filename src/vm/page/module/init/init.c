#include<stdio.h>

// 启动页式虚拟存储器
void page_virtual_memory_init(){

	// 打印页式存储器的欢迎语
	ui_print_vm_welcome(VM_TYPE_SEGMENT_PAGE);

	// 进入命令行交互环境
	while(RES_OK == command_enter_interactive_env()){

	
	}

}