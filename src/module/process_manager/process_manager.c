#include <stdio.h>

// 创建新的进程
void process_manager_new(Process process){


}

// 销毁进程
void process_manager_halt(int process_id){


}

// 获取到所有的进程
Process* process_manager_get_all(PCB pcb){

	// 根据 PCB 去返回全部的进程(包括进程的状态)
	// return pcb->
}

// 打印所有的进程
void process_manager_print_all(PCB pcb){

	int i=0;
	ProcessLinkedNode *p = pcb->head;
	
	printf("The total process count is : %d , now print the all process below\n",pcb->count);
	while(NULL!=p){ // 这样写的好处是防止写成赋值号，而且更突出重点

		++i;
		printf("%dth process , id: %d , name: %s \n"i,p->process_id, p->process_name);
		p = p->p;
	}
	printf("-----------------END-----------------\n");
	
}

