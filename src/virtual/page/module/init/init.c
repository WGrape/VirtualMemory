#include<stdio.h>

// 启动页式虚拟存储器
void page_virtual_memory_init(){

	PCB pcb = {NULL};
	int type;

	// 打印页式存储器的欢迎语
	ui_print_welcome(VM_TYPE_SEGMENT_PAGE);

	// 进入命令行环境
	command_enter_interactive_env(VM_TYPE_SEGMENT_PAGE);
}