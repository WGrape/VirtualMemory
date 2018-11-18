#ifndef INCLUDE_OBJECT_VMModel_H
#define INCLUDE_OBJECT_VMModel_H

// 虚拟存储器Model[主要是把一些 Memory,PCB,PageTable 结合到一起,打包传递给相关单元使用]
typedef struct{

	Memory memory; // 当前的内存
	
	PCB pcb; // PCB块
	
	PageTable page_table; // 页表

}VMModel;


#endif

