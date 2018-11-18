#ifndef INCLUDE_OBJECT_PAGE_TABLE_ITEM_H
#define INCLUDE_OBJECT_PAGE_TABLE_ITEM_H


#include <stdio.h>


// 页表项
// 页表是一张存储着主存中的虚页号和实页号的对照表

typedef struct {

	int virtual_page_number; // 虚页号
	int physical_page_number; // 实页号
	int load_flag; // 是否已装入内存

}PageTableItem;


#endif
