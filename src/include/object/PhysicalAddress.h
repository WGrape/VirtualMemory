#ifndef INCLUDE_OBJECT_PHYSICAL_ADDRESS_H
#define INCLUDE_OBJECT_PHYSICAL_ADDRESS_H

// 物理地址
typedef struct{

	int physical_page_number; // 实页号
	int offset;// 偏移量

}PhysicalAddress;


#endif
