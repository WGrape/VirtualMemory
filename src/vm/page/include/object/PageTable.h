#ifndef INCLUDE_OBJECT_PAGE_TABLE_H
#define INCLUDE_OBJECT_PAGE_TABLE_H


#include <stdio.h>

// 页表结构
typedef struct {

	int count; // 记录当前所有的页表项个数
	PageTableItem page_table_items[MEMORY_UNIT_COUNT]; // 页表项

}PageTable;

#endif

