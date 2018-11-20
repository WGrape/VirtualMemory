#include<stdio.h>
#include <string.h>
#include <vm/segment/include/object/SegmentVMModel.h>
#include <vm/segment/module/ui/ui.h>
#include <include/define/constant.h>
#include <vm/segment/include/define/constant.h>
#include <vm/segment/module/pmu/pmu.h>
#include <vm/segment/module/mmu/mmu.h>
#include <vm/segment/module/vmmu/vmmu.h>
#include <module/system/system.h>
#include <include/object/Process.h>
#include <include/define/rescode.h>

// 声明
static Process segment_command_input_data_of_new_process();
static Process segment_command_input_data_of_halt_process();
static void segment_command_handle_new_process(SegmentVMModel *vm_model_pointer);
static void segment_command_handle_halt_process(SegmentVMModel *vm_model_pointer);


// 入口
void segment_command_enter_interactive_env(SegmentVMModel *vm_model_pointer){
	
	int option; // 菜单选项的选择

	for(;;){ // 外层是while(1)大循环

		// 打印菜单并选择选项
		segment_ui_print_vm_menu_view();
		scanf("%d",&option);
		switch(option){

			// 创建一个新的进程
			case VM_MENU_OPTION_NEW_PROCESSES:
				segment_command_handle_new_process(vm_model_pointer);break;

			// 中止一个进程
			case VM_MENU_OPTION_HALT_PROCESSES:
				segment_command_handle_halt_process(vm_model_pointer);break;

			// 打印出全部的进程
			case VM_MENU_OPTION_PRINT_ALL_PROCESSES:
				segment_pmu_print_all_processes(vm_model_pointer);break;

			// 打印出所有的段表项
			case VM_MENU_OPTION_PRINT_ALL_SEGMENT_TABLE_ITEMS:
				segment_vmmu_print_all_segment_table_items(vm_model_pointer);break;

			// 退出
			default:
				return;
		}
	}
}



// 命令行输入新建进程的信息
static Process segment_command_input_data_of_new_process(){

	char name[PROCESS_LIMIT_NAME_MAX_LEN];
	printf("Please enter the name of process: ");
	scanf("%s",name);

	// 记录进程的名称
	Process process;
	strcpy(process.process_name , name);
	return process;
}

// 命令行处理新建一个进程
static void segment_command_handle_new_process(SegmentVMModel *vm_model_pointer){

	segment_mmu_load_process(
			segment_vmmu_register_process(
					segment_pmu_new_process(

							segment_command_input_data_of_new_process(), vm_model_pointer
					), vm_model_pointer
			), vm_model_pointer
	);

	segment_ui_print_operate_success();
}



// 命令行输入中止进程的信息
static Process segment_command_input_data_of_halt_process(){

    int process_id;
    printf("Please enter the id of process: ");
    scanf("%d",&process_id);

	// 记录进程的 id , 根据 pcb 块中的 count , count+1即为新进程的 id
    Process process = {process_id:process_id};
    return process;
}

// 命令行处理中止一个进程
static void segment_command_handle_halt_process(SegmentVMModel *vm_model_pointer){

	int res = segment_pmu_halt_process(
			segment_vmmu_unregister_process(
					segment_mmu_unload_process(

							segment_command_input_data_of_halt_process(), vm_model_pointer
					), vm_model_pointer
			), vm_model_pointer
	);

	if(RES_OK == res){

		segment_ui_print_operate_success();
	}
}

