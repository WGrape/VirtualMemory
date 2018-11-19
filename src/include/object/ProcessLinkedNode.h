#ifndef INCLUDE_OBJECT_PROCESS_LINKED_NODE_H
#define INCLUDE_OBJECT_PROCESS_LINKED_NODE_H

#include "VirtualAddress.h"

// 进程链结点
typedef struct ProcessLinkedNode{

	// 由 pmmu 负责填充
	int process_id; // 进程的 id
	char *process_name;   // 进程的 name
	char *process_extra; // 进程的 extra 信息


	VirtualAddress virtual_address; 	 // 进程的虚地址 = 虚页号+页内地址
	// PhysicalAddress *physical_address; 	 // 进的实地址 = 实页号+页内地址

	// 必须这样写 typedef struct ProcessLinkedNode
	struct ProcessLinkedNode *next; // 指向下一个进程链结点

}ProcessLinkedNode;


#endif


