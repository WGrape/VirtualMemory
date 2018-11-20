#ifndef INCLUDE_OBJECT_PROCESS_LINKED_NODE_H
#define INCLUDE_OBJECT_PROCESS_LINKED_NODE_H

#include "VirtualAddress.h"
#include <include/define/constant.h>


// 进程链结点
typedef struct ProcessLinkedNode{

	// 由 pmmu 负责填充
	int process_id; // 进程的 id
	char process_name[ PROCESS_LIMIT_NAME_MAX_LEN ];   // 进程的 name
	char process_extra[ PROCESS_LIMIT_EXTRA_MAX_LEN ]; // 进程的 extra 信息


	VirtualAddress virtual_address; 	 // 进程的虚地址 = 虚页号+页内地址
	// PhysicalAddress *physical_address; 	 // 进的实地址 = 实页号+页内地址

	// 必须这样写 typedef struct ProcessLinkedNode
	struct ProcessLinkedNode *next; // 指向下一个进程链结点

}ProcessLinkedNode;


#endif


