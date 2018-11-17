#include<stdio.h>

// 启动页式虚拟存储器
void page_virtual_memory_init(){

	int option;
	PCB pcb = {NULL};

	// 打印页式存储器的欢迎语
	ui_print_vm_welcome(VM_TYPE_SEGMENT_PAGE);

	while(RES_OK == command_enter_interactive_env(VM_TYPE_SEGMENT_PAGE)){

		ui_print_vm_menu();
		scanf("%d",&option);
		switch(option){

			// 打印出所有的 process
			case VM_MENU_OPTION_PRINT_ALL_PROCESSES:
			break;
			
			// 新建 process
			case VM_MENU_OPTION_NEW_PROCESSES:
			break;

			// 
			case VM_MENU_OPTION_HALT_PROCESSES:
			break;

		}
	}

}