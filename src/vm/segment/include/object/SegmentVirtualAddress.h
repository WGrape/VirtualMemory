#ifndef VM_SEGMENT_INCLUDE_OBJECT_VIRTUAL_ADDRESS_H
#define VM_SEGMENT_INCLUDE_OBJECT_VIRTUAL_ADDRESS_H

// 虚拟地址
typedef struct{

	int segment_number; // 段号
	int offset; // 段内地址

}VirtualAddress;


#endif