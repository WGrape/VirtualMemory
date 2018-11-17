#include <stdio.h>

int main(){

	int vm_type;
	Memory memory;

	while(1){

		// 分配内存
		memory.pr = memory_manager_alloc();

		ui_print_launch();

		// 选择使用不同的虚拟存储器
		scanf("%d",&vm_type);
		switch(virtual_memory_type){

			// 页式虚拟存储器
			case VM_TYPE_PAGE:
			page_virtual_memory_init();break;

			// 段式虚拟存储器
			case VM_TYPE_SEGMENT:
			segment_virtual_memory_init();break;

			// 段页式虚拟存储器
			case VM_TYPE_SEGMENT_PAGE:
			segment_page_virtual_memory_init();break;

			// 退出
			default:
			break;
		}

		// 回收内存
		memory_manager_collec(memory.pr);
	}

	printf("\nBye\n");
	return 0;
}
