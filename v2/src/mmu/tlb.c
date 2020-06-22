/*
 * MMU中的cache
 * 1. 缓存页表, 即缓存线性地址(虚拟地址)到物理地址的映射关系
 * 2. 替换算法
 * 3. 数据结构: 页表条目数组
 */
#include <stdlib.h>

void cahce_flush_tlb_all(){
}

void cache_flush_tlb_mm(struct mm_struct *mm){

}

void flush_tlb_range(struct vm_area_struct *vma, unsigned long start, unsigned long end){

}

