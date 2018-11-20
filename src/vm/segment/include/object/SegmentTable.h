#ifndef VM_SEGMENT_INCLUDE_OBJECT_PAGE_TABLE_H
#define VM_SEGMENT_INCLUDE_OBJECT_PAGE_TABLE_H

#include <stdio.h>
#include "SegmentTableItemLinkedNode.h"

// 段表结构
typedef struct {

	SegmentTableItemLinkedNode *head; // 指向第一个段表项结点
	SegmentTableItemLinkedNode *tail; // 指向最后一个段表项结点
	
	int segment_table_item_count; // 记录当前所有的段表项个数

}SegmentTable;

#endif

