// 内存中只存放 int 数据( process_id )

#include <stdlib.h>
#include <include/object/Process.h>
#include <include/define/constant.h>
#include <vm/page/include/object/VMModel.h>
#include <vm/page/module/ui/ui.h>
#include <module/system/system.h>

// 载入一个进程到内存中
Process mmu_load_process(Process process,VMModel *vm_model_pointer){

	// 进程载入内存中
	// int process_count = vm_model_pointer->pcb.process_count; // 获取PCB中当前的进程个数
	*(vm_model_pointer->memory.next) = process.process_id;
	(vm_model_pointer->memory.next)++;

	// 想想还有哪里需要记录 ...

	return process;
}

// 从内存中移除一个进程
Process mmu_unload_process(Process process,VMModel *vm_model_pointer){

	// 根据进程的id去内存中查找，并移除
	if(process.process_id>=1 && process.process_id<=MEMORY_UNIT_COUNT){

		// 如果用户输入的进程 id 在管控的内存范围之内 , 直接修改覆盖 , 无论是否存在进程( 因为进程是否存在, 都可以覆盖掉覆盖 )
		*((vm_model_pointer->memory.pr)+(process.process_id)-1) = -999999;
	}

	return process;
}



// 分配内存
int* mmu_alloc_memory(){

	int *p = (int*)malloc(sizeof(int)*1000);
	if(!p){

		exit(1);
	}

	return p;
}

// 收回内存
void mmu_collec_memory(int *p){

	free(p);
}



// 分配 ProcessLinkedNode
ProcessLinkedNode* mmu_alloc_process_linked_node(){

	ProcessLinkedNode *p = (ProcessLinkedNode*)malloc(sizeof(ProcessLinkedNode)*1);

	if( NULL == p){

        system_exit("malloc with a failure");
	}

	return p;
}

// 回收 ProcessLinkedNode
void mmu_collec_process_linked_node(ProcessLinkedNode *p){

	free(p);
}



// 分配 PageTableItemLinkedNode
PageTableItemLinkedNode* mmu_alloc_page_table_item_linked_node(){

	PageTableItemLinkedNode *p = (PageTableItemLinkedNode*)malloc(sizeof(PageTableItemLinkedNode)*1);	
	if(NULL == p){

		exit(1);
	}

	return p;
}

// 回收 PageTableItemLinkedNode
void mmu_collec_page_table_item_linked_node(PageTableItemLinkedNode *p){

	free(p);
}


