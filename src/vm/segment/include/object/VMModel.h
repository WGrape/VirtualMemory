#ifndef VM_SEGMENT_INCLUDE_OBJECT_VM_Model_H
#define VM_SEGMENT_INCLUDE_OBJECT_VM_Model_H

#include <include/object/Memory.h>
#include <include/object/PCB.h>
#include "SegmentTable.h"

// 虚拟存储器Model[主要是把一些 Memory,PCB,PageTable 结合到一起,打包传递给相关单元使用]
typedef struct{

	Memory memory; // 当前的内存
	
	PCB pcb; // PCB块
	
	SegmentTable segment_table; // 段表

}VMModel;


#endif

