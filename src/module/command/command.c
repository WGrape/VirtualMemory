#include<stdio.h>


static PageVMCommandPackage page_vm_command_package;
static SegmentPageVMCommandPackage segment_page_vm_command_package;
static SegmentVMCommandPackage segment_vm_commandPackage;


int command_enter_interactive_env(int vm_type){

	
	int option; // 菜单选项的选择

	command_construct(); // 初始化

	while(1){

		ui_print_vm_menu();
		scanf("%d",&option);
		switch(option){

			case VM_MENU_OPTION_PRINT_ALL_PROCESSES: // 打印出所有的 process
			case VM_MENU_OPTION_NEW_PROCESSES: // 新建 process
			case VM_MENU_OPTION_HALT_PROCESSES: // 中止一个进程
				
				command_handle_vm_type_combine_option(vm_type,option);
				break;

			// 退出
			default:
				command_destruct();
				return(); 
				break;
		}
	}

}



// 命令行输入新建进程的信息
Process command_input_data_of_new_process(Process process){

	char name[PROCESS_NAME_LEN];
	printf("Please enter the name of process: ");
	scanf("%s",&name);

	// 根据 pcb 块中的 count , count+1即为新进程的 id
	Process process = {process_name:name};

	return process;
}


// 命令行输入中止进程的信息
Process command_input_data_of_halt_process(){

	int process_id;
	printf("Please enter the id of process: ");
	scanf("%d",&process_id);

	// 根据 pcb 块中的 count , count+1即为新进程的 id
	Process process = {process_id:process_id};

	return process;
}

// 初始化
static void command_construct(){

	if(vm_type==VM_TYPE_PAGE){

		page_vm_command_package = page_vm_get_command_package();
	}else if(vm_type==VM_TYPE_SEGMENT){

		segment_page_vm_command_package = segment_vm_get_command_package();
	}else{

		segment_vm_commandPackage = segment_page_vm_get_command_package();
	}
}

// 析构
static void command_destruct(){

	page_vm_command_package = {};
	segment_page_vm_command_package = {};
	segment_vm_commandPackage ={};
}



// 命令行处理选项
static void command_handle_vm_type_combine_option(int vm_type,int option){

	if(vm_type==VM_TYPE_PAGE){

		command_handle_page_vm_option(option);

	}else if(vm_type==VM_TYPE_SEGMENT){

		command_handle_segment_vm_option(option);
	}else{

		command_handle_segment_page_vm_option(option);
	}
}

// 命令行处理页式虚拟存储器的选项
static void command_handle_page_vm_option(int option){

	// 打印出全部的进程
	if(VM_MENU_OPTION_PRINT_ALL_PROCESSES==option){

		pmu_print_all_processes(page_vm_command_package);
	}else if(VM_MENU_OPTION_NEW_PROCESSES==option){

		mmu_load_process(vmmu_register_process(pmu_new_process( command_input_data_of_new_process(page_vm_command_package) )));
	}else{

		mmu_unload_process(vmmu_unregister_process(pmu_halt_process( command_input_data_of_halt_process(page_vm_command_package) )));
	}
}

// 命令行处理段式虚拟存储器的选项
static void command_handle_segment_vm_option(int option){

}

// 命令行处理段页式虚拟存储器的选项
static void command_handle_segment_page_vm_option(int option){

}
