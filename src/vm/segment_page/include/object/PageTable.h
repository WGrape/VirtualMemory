#include <stdio.h>


// 页表
typedef struct {

	int count; // 记录当前所有的页表项个数
	PageTableItem page_table_items[MEMORY_UNIT_COUNT]; // 页表项

}PageTable;



