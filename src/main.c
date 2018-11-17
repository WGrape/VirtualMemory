#include <stdio.h>

int main(){

	int type;

	while(1){

		// 选择启动不同的虚拟存储器
		printf("Choose the different types of virtual memory\n1(Page) 2(Segment) 3(SegmentPage) : ");
		scanf("%d",&type);

		Memory memory = {alloc_memory()};

		if(type==1){


		}


		collec_memory(memory.p);

	}

	return 0;
}
