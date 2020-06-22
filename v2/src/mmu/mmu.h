#ifndef MODULE_MMU_H
#define MODULE_MMU_H

#include <include/type.h>
#include <include/const.h>

/**
 * @define 定义物理内存相关数据指标
 * PG_SIZE: 物理页面4K, 1024*4 = 4096B
 * MO_SIZE: 物理内存1M, 1M = 1024KB = 1024*1024B = 1048576B
 */
#define PG_SIZE 4096
#define MO_SIZE 1048576

/**
 * @var 物理内存的基本单位
 * 页面大小为PG_SIZE
 */
struct page {

    unsigned long flags;
    int count;
    struct address_space *mapping;
    void *virtual;
    struct list_head lru;
};

/**
 * @var 定义全局物理内存
 */
struct ram __ram;
struct ram {

    byte *head; // 物理内存起始地址
    byte *tail; // 物理内存结束地址
    int size; // 总计内存空间:单位字节
    int free; // 剩余内存空间:单位字节
};

/**
 * @var 定义全局物理区
 * 内核空间:[3G, 4G], 共1G的内存空间
 * 高端内存:[3G, 3G+896M]
 * 内核线性映射区:[3G, 3G+896M)
 * 临时映射区:[3G+896M, 4G]
 *
 */
struct zone {

};

/**
 * 内存区域类型
 */
enum zone_type{

    ZONE_DMA, // 外设直接访问内存区/低地址
    ZONE_NORMAL, // 用户空间
    ZONE_HIGHMEM, // 内核空间/高地址
};

extern struct ram __ram;

extern byte *mmu_malloc(unsigned int size);

extern void mmu_ram_initialization();

#endif
