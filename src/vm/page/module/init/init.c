#include<stdio.h>
#include <vm/page/include/object/VMModel.h>
#include <vm/page/module/ui/ui.h>
#include <vm/page/module/command/command.h>
#include <vm/page/module/vmmu/vmmu.h>
#include <vm/page/module/pmu/pmu.h>
#include <vm/page/module/mmu/mmu.h>

static VMModel __vm_model__; // 全局静态的 __vm_model__ , 存储了全部的数据 = Memory+PCB+PageTable
static VMModel *__vm_model_pointer__; // 指向 __vm_model__ 的指针

// 仅限内部使用
static VMModel page_vm_get_vm_model(){

	// 分配一块内存
	int *memory_pr = mmu_alloc_memory();

	VMModel vm_model = {
		memory : {

			pr: memory_pr,
			next:memory_pr
		},
		pcb : {

			head:NULL,
			tail:NULL,
			process_count:0
		},
		page_table : {

			page_table_item_count:0
			
		}

	};

	return vm_model;
}

// 构造函数
static void page_vm_construct(){

	__vm_model__ = page_vm_get_vm_model();
	__vm_model_pointer__ = &(__vm_model__);
}

// 析构
static void page_vm_destruct(){

	vmmu_free(

			pmu_free(__vm_model_pointer__) // 进程管理单元释放掉所占内存
	); // 虚拟存储器管理单元释放掉所占内存

	// 销毁
	VMModel vm_model = {

		memory : {

				pr: NULL,
				next:NULL
		},
		pcb : {

				head:NULL,
				tail:NULL,
				process_count:0
		},
		page_table : {

				page_table_item_count:0
		}
	};
	__vm_model__ = vm_model;
	__vm_model_pointer__ = NULL;
}

// 启动页式虚拟存储器
void page_vm_init(){

	// 构造
	page_vm_construct();

	// 打印页式存储器的欢迎语
	ui_print_vm_welcome_view();

	// 进入命令行交互环境
	command_enter_interactive_env(__vm_model_pointer__);

	// 析构
	page_vm_destruct();
}
