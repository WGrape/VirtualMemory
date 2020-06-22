#ifndef INCLUDE_TYPE_H
#define INCLUDE_TYPE_H

/*
 * 自定义类型
 * 1. byte类型, 主要用于内存操作
 * 2. pgd_t类型, 页全局目录项
 * 3. pud_t类型, 页上级目录项
 * 4. pmd_t类型, 页中间目录项
 * 5. pte_t类型, 页表项
*/
typedef unsigned char byte;
typedef unsigned long pgd_t;
typedef unsigned long pud_t;
typedef unsigned long pmd_t;
typedef unsigned long pte_t;

/*
 * 自定义类型
 * 1. linear_addr, 线性地址(虚拟地址)类型
 * 2. physics_add, 物理地址类型
 */
typedef unsigned long linear_addr;
typedef unsigned long physics_addr;


#endif