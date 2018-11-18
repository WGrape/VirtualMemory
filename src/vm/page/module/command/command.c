#include<stdio.h>


static VMModel __vm_model__;


void command_enter_interactive_env(VMModel vm_model){
	
	int option; // 菜单选项的选择

	command_construct(vm_model); // 初始化

	while(1){

		// 打印菜单并选择选项
		ui_print_vm_menu();
		scanf("%d",&option);
		switch(option){

			// 打印出全部的进程
			case VM_MENU_OPTION_PRINT_ALL_PROCESSES:
				pmu_print_all_processes(vm_model.pcb);
				break;

			// 创建一个新的进程
			case VM_MENU_OPTION_NEW_PROCESSES:
				mmu_load_process(
					vmmu_register_process(
						pmu_new_process( 
						
							command_input_data_of_new_process(), __vm_model__
						), __vm_model__
					), __vm_model__
				);
				break;

			// 中止一个进程
			case VM_MENU_OPTION_HALT_PROCESSES:
				mmu_unload_process(
					vmmu_unregister_process(
						pmu_halt_process( 
						
							command_input_data_of_halt_process(), __vm_model__
						), __vm_model__
					), __vm_model__
				);
				break;

			// 退出
			default:
				command_destruct();
				return(); 
				break;
		}
	}

}

// 构造函数
static void command_construct(VMModel vm_model){

	__vm_model__ = vm_model;
}
// 析构
static void command_destruct(){

	vmmu_free(

		pmu_free(__vm_model__) // 进程管理单元释放掉所占内存
	); // 虚拟存储器管理单元释放掉所占内存

	// 销毁
	__vm_model__ = {};
}


// 命令行输入新建进程的信息
static Process command_input_data_of_new_process(){

	char name[PROCESS_NAME_LEN];
	printf("Please enter the name of process: ");
	scanf("%s",&name);

	// 根据 pcb 块中的 count , count+1即为新进程的 id
	Process process = {process_name:name};

	return process;
}


// 命令行输入中止进程的信息
static Process command_input_data_of_halt_process(){

	int process_id;
	printf("Please enter the id of process: ");
	scanf("%d",&process_id);
	Process process = {process_id:process_id};

	return process;
}
