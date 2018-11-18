#ifndef INCLUDE_OBJECT_PROCESS_LINKED_NODE_H
#define INCLUDE_OBJECT_PROCESS_LINKED_NODE_H

// 进程链结点
typedef struct{

	// 由 pmmu 负责填充
	int process_id; // 进程的 id
	char process_name[PROCESS_NAME_LEN];   // 进程的 name
	char process_extra[PROCESS_EXTRA_LEN]; // 进程的 extra 信息

	// 由 vmmu 负责填充
	int virtual_page_number; // 虚页号
	int offset; 			 // 页内地址/页内偏移/偏移量
	VirtualAddress *virtual_address; 	 // 进程的虚地址
	PhysicalAddress *physical_address; 	 // 进的物理地址(实地址)


	ProcessLinkedNode *next; // 指向下一个进程链结点

}ProcessLinkedNode;


#endif