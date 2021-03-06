#ifndef VM_PAGE_INCLUDE_OBJECT_PAGE_TABLE_ITEM_LINKED_NODE_H
#define VM_PAGE_INCLUDE_OBJECT_PAGE_TABLE_ITEM_LINKED_NODE_H

#include <stdio.h>


// 页表项
// 页表是一张存储着主存中的虚页号和实页号的对照表

typedef struct PageTableItemLinkedNode {

	int virtual_page_number; // 虚页号
	int physical_page_number; // 实页号
	
	int load; // 是否已装入内存

	struct PageTableItemLinkedNode *next; // 指向下一个页表项结点

}PageTableItemLinkedNode;


#endif
