#include<stdio.h>

int command_enter_interactive_env(){

	int option;
	scanf("%d",&option);

	ui_print_menu();

	switch(option){

		case 1:
		page_virtual_memory_init();break; // Print All Proccesses

		case 2:
		// 段式虚拟存储器
		segment_virtual_memory_init();break; 、// New Process

		case 3:
		// 段页式虚拟存储器
		segment_page_virtual_memory_init();break; // Destroy Process

		default:
		return 0;break;
	}

	return 1;
}




