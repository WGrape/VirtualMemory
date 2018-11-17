#include <stdio.h>


// 页表
// 页表是一张存储着主存中的虚页号和实页号的对照表

typedef struct {

	int virtual_page_number; // 虚页号
	int page_number; // 实页号
	int load_flag; // 

}PageTable;



