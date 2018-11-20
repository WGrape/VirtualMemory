#ifndef INCLUDE_OBJECT_PCB_H
#define INCLUDE_OBJECT_PCB_H

#include "vm/page/include/object/ProcessLinkedNode.h"

// 进程控制块
typedef struct{

	SegmentProcessLinkedNode *head; // 指向第一个进程链结点
	SegmentProcessLinkedNode *tail; // 指向最后一个进程链结点
	
	int process_count; // 记录当前的进程个数
	
}SegmentPCB;

#endif