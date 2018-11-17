#include <stdio.h>

int main(){

	int type;
	Memory memory;

	while(1){

		// 分配内存
		memory.pr = alloc_memory();

		// 选择启动不同的虚拟存储器
		printf("Choose the different types of virtual memory\n1(Page) 2(Segment) 3(SegmentPage) : ");
		scanf("%d",&type);

		if(type==1){

			// 页式虚拟存储器
			page_virtual_memory_init();

		}else if(type==2){

			// 段式虚拟存储器
			segment_virtual_memory_init();

		}else{

			// 段页式虚拟存储器
			segment_page_virtual_memory_init();
		}

		// 回收内存
		collec_memory(memory.pr);
	}

	return 0;
}
