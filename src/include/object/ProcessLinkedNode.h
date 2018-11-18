#ifndef INCLUDE_OBJECT_PROCESS_LINKED_NODE_H
#define INCLUDE_OBJECT_PROCESS_LINKED_NODE_H

typedef struct{

	int process_id; // 进程的 id
	char process_name[PROCESS_NAME_LEN]; // 进程的 name
	char process_extra[PROCESS_EXTRA_LEN]; // 进程的 extra 信息

	int virtual_page_number; // 虚页号
	int offset; // 页内地址/页内偏移/偏移量

	ProcessLinkedNode *p; // 指向下一个进程链结点

}ProcessLinkedNode;


#endif