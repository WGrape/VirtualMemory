#include<stdio.h>
#include <string.h>
#include <vm/page/include/object/VMModel.h>
#include <vm/page/module/ui/ui.h>
#include <include/define/constant.h>
#include <vm/page/module/pmu/pmu.h>
#include <vm/page/module/mmu/mmu.h>
#include <vm/page/module/vmmu/vmmu.h>
#include <module/system/system.h>
#include <include/object/Process.h>

// 声明
static Process command_input_data_of_new_process();
static Process command_input_data_of_halt_process();
static void command_handle_new_process(VMModel *vm_model_pointer);
static void command_handle_halt_process(VMModel *vm_model_pointer);


// 入口
void command_enter_interactive_env(VMModel *vm_model_pointer){
	
	int option; // 菜单选项的选择

	for(;;){ // 外层是while(1)大循环

		// 打印菜单并选择选项
		ui_print_vm_menu_view();
		scanf("%d",&option);
		switch(option){

			// 打印出全部的进程
			case VM_MENU_OPTION_PRINT_ALL_PROCESSES:
				pmu_print_all_processes(vm_model_pointer);break;

			// 创建一个新的进程
			case VM_MENU_OPTION_NEW_PROCESSES:
				command_handle_new_process(vm_model_pointer);break;

			// 中止一个进程
			case VM_MENU_OPTION_HALT_PROCESSES:
				command_handle_halt_process(vm_model_pointer);break;

			case VM_MENU_OPTION_PRINT_ALL_PAGE_TABLE_ITEMS:
				pmu_print_all_page_table_items(vm_model_pointer);break;

			// 退出
			default:
				return;
		}
	}
}



// 命令行输入新建进程的信息
static Process command_input_data_of_new_process(){

	char name[PROCESS_LIMIT_NAME_MAX_LEN];
	printf("Please enter the name of process: ");
	scanf("%s",name);

	// 记录进程的名称
	Process process;
	strcpy(process.process_name , name);
	return process;
}

// 命令行处理新建一个进程
static void command_handle_new_process(VMModel *vm_model_pointer){

	mmu_load_process(
			vmmu_register_process(
					pmu_new_process(

							command_input_data_of_new_process(), vm_model_pointer
					), vm_model_pointer
			), vm_model_pointer
	);

	ui_print_operate_success();
}



// 命令行输入中止进程的信息
static Process command_input_data_of_halt_process(){

    int process_id;
    printf("Please enter the id of process: ");
    scanf("%d",&process_id);

	// 记录进程的 id , 根据 pcb 块中的 count , count+1即为新进程的 id
    Process process = {process_id:process_id};
    return process;
}

// 命令行处理中止一个进程
static void command_handle_halt_process(VMModel *vm_model_pointer){

	pmu_halt_process(
			vmmu_unregister_process(
					mmu_unload_process(

							command_input_data_of_halt_process(), vm_model_pointer
					), vm_model_pointer
			), vm_model_pointer
	);

	ui_print_operate_success();
}

