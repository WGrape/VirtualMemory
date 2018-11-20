#include<stdio.h>
#include <vm/segment/include/object/SegmentVMModel.h>
#include <vm/segment/module/ui/ui.h>
#include <vm/segment/module/command/command.h>
#include <vm/segment/module/vmmu/vmmu.h>
#include <vm/segment/module/pmu/pmu.h>
#include <vm/segment/module/mmu/mmu.h>

static SegmentVMModel __vm_model__; // 全局静态的 __vm_model__ , 存储了全部的数据 = Memory+PCB+PageTable
static SegmentVMModel *__vm_model_pointer__; // 指向 __vm_model__ 的指针

// 仅限内部使用
static SegmentVMModel segment_vm_get_vm_model(){

	// 分配一块内存
	int *memory_pr = segment_mmu_alloc_memory();

	SegmentVMModel vm_model = {
		memory : {

			pr: memory_pr,
			next:memory_pr
		},
		pcb : {

			head:NULL,
			tail:NULL,
			process_count:0
		},
		segment_table : {

			segment_table_item_count:0
		}

	};

	return vm_model;
}

// 构造函数
static void segment_vm_construct(){

	__vm_model__ = segment_vm_get_vm_model();
	__vm_model_pointer__ = &(__vm_model__);
}

// 析构
static void segment_vm_destruct(){

	segment_mmu_free(
			segment_vmmu_free(
					segment_pmu_free(__vm_model_pointer__) // 进程管理单元释放掉所占内存
			) // 虚拟存储器管理单元释放掉所占内存
	);// 物理内存释放掉

	// 销毁
	SegmentVMModel vm_model = {

		memory : {

				pr: NULL,
				next:NULL
		},
		pcb : {

				head:NULL,
				tail:NULL,
				process_count:0
		},
		segment_table : {

				segment_table_item_count:0
		}
	};
	__vm_model__ = vm_model;
	__vm_model_pointer__ = NULL;
}

// 启动段式虚拟存储器
void segment_vm_init(){

	// 构造
	segment_vm_construct();

	// 打印段式存储器的欢迎语
	segment_ui_print_vm_welcome_view();

	// 进入命令行交互环境
	segment_command_enter_interactive_env(__vm_model_pointer__);

	// 析构
	segment_vm_destruct();
}
