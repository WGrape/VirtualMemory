#ifndef INCLUDE_OBJECT_MEMORY_H
#define INCLUDE_OBJECT_MEMORY_H

// 物理内存
typedef struct {
	
	int *pr; // 指向内存的基地址
	int *next; // 指向内存的下一个单元

}Memory;


#endif