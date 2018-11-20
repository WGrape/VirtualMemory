#ifndef VM_PAGE_INCLUDE_OBJECT_PAGE_TABLE_H
#define VM_PAGE_INCLUDE_OBJECT_PAGE_TABLE_H

#include <stdio.h>
#include "PageTableItemLinkedNode.h"

// 页表结构
typedef struct {

	PageTableItemLinkedNode *head; // 指向第一个页表项结点
	PageTableItemLinkedNode *tail; // 指向最后一个页表项结点
	
	int page_table_item_count; // 记录当前所有的页表项个数

}PageTable;

#endif

