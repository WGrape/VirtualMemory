#include <stdio.h>

int main(){

	int virtual_memory_type;
	Memory memory;

	while(1){

		// 分配内存
		memory.pr = memory_manager_alloc();

		// 选择启动不同的虚拟存储器
		printf("Choose the different types of virtual memory\n1(Page) 2(Segment) 3(SegmentPage) 4(Exit) : ");
		scanf("%d",&virtual_memory_type);
		switch(virtual_memory_type){

			case 1:
			// 页式虚拟存储器
			page_virtual_memory_init();break;

			case 2:
			// 段式虚拟存储器
			segment_virtual_memory_init();break;

			case 3:
			// 段页式虚拟存储器
			segment_page_virtual_memory_init();break;

			default:
			break;
		}

		// 回收内存
		memory_manager_collec(memory.pr);
	}

	printf("\nBye\n");
	return 0;
}
