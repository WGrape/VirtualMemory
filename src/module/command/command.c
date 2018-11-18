#include<stdio.h>

int command_enter_interactive_env(int vm_type){

	PCB pcb = {NULL};
	int option;
	ui_print_vm_menu();
	scanf("%d",&option);
	switch(option){

		// 打印出所有的 process
		case VM_MENU_OPTION_PRINT_ALL_PROCESSES:
			
			process_manager_print_all(); 
			break;
		
		// 新建 process
		case VM_MENU_OPTION_NEW_PROCESSES:
			
			process_manager_new(command_input_data_of_new_process(pcb));
			break;

		// 中止一个进程
		case VM_MENU_OPTION_HALT_PROCESSES:

			process_manager_new(command_input_data_of_halt_process(pcb));
			break;

		// 退出
		default:
			return(); 
			break;
	}
}




Process command_input_data_of_new_process(PCB pcb){

	char name[PROCESS_NAME_LEN];
	printf("Please enter the name of process: ");
	scanf("%s",&name);

	// 根据 pcb 块中的 count , count+1即为新进程的 id
	Process process = {process_id:(pcb->count)+1,process_name:name};

}


