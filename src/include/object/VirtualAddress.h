#ifndef INCLUDE_OBJECT_VIRTUAL_ADDRESS_H
#define INCLUDE_OBJECT_VIRTUAL_ADDRESS_H

// 虚拟地址
typedef struct{

	int virtual_page_number; // 虚页号
	int offset; // 偏移量

}VirtualAddress;


#endif