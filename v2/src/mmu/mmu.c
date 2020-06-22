#include <stdlib.h>
#include <include/type.h>
#include "mmu.h"

/**
 * @document 物理内存管理单元MMU
 * 1. New出新内存作为"物理内存"使用
 * 2. 线性地址到物理地址的转换
 * 3. 伙伴系统与物理内存的管理维护, 如内存碎片处理
 */

/**
 * @function 分配物理内存并返回byte指针
 * @param size unsigned int
 * @return byte*
 */
byte *mmu_malloc(unsigned int size) {

    return (byte *) malloc(size);
}

/**
 * @function 完成物理内存的分配
 * @param void
 * @return void
 */
void mmu_ram_initialization() {

    byte *head = mmu_malloc(MO_SIZE);
    byte *tail = head + MO_SIZE;
    __ram.head = head;
    __ram.tail = tail;
    __ram.size = MO_SIZE;
    __ram.free = 0;

    unsigned long zones_size[MAX_NR_ZONES] = {0, 0, 0};
    unsigned long max_dma, high, low;


}

void mmu_buddy_() {

}