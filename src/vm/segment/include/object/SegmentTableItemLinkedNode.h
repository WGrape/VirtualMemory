#ifndef VM_SEGMENT_INCLUDE_OBJECT_SEGMENT_TABLE_ITEM_LINKED_NODE_H
#define VM_SEGMENT_INCLUDE_OBJECT_SEGMENT_TABLE_ITEM_LINKED_NODE_H

#include <stdio.h>


// 段表项
// 段表 : 记录了与某个段对应的段号、装入位、段起点、段长等信息
// 由于段的长度可变，所以短标中要给出隔断的起始地址和段的长度
typedef struct SegmentTableItemLinkedNode {

	int segment_number;  // 段号
	int segment_address; // 段的起始地址
	int segment_length;  // 段长
	int load; // 是否已装入内存

	struct SegmentTableItemLinkedNode *next; // 指向下一个段表项结点

}SegmentTableItemLinkedNode;


#endif
