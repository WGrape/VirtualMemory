#include <stdio.h>




// 创建新的进程
Process pmu_new_process(Process process){

	// 记录到表中

}

// 销毁进程
Process pmu_halt_process(Process process){


}

// 打印所有的进程
void pmu_print_all_processes(PCB pcb){

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

