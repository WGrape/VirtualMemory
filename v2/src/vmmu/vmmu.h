#ifndef MODULE_VMMU_H
#define MODULE_VMMU_H

/**
 * @var 虚拟区间描述符
 * 进程所占内存的基本单元
 * 大小是物理内存页面的整数倍
 */
struct vm_area_struct {

    struct task_struct *vm_task;
    linear_addr vm_start, vm_end;
    struct vm_area_struct *vm_next;
    struct file * vm_file;
};

/**
 * @var 进程内存描述符
 * 进程所占的内存空间
 */
struct mm_struct {

    struct vm_area_struct *mmap; // list of VMAs
    int map_count; // number of VMAs
    pgd_t *pgd; // 指向页全局目录
    linear_addr start_code, end_code, start_data, end_data; // 代码段、数据段的地址空间范围
    linear_addr start_brk, brk, start_stack, end_stack; // 堆、栈的地址空间范围
};

/*
 * 页面从内存换到磁盘
 */ 
vmmu_swapoff();

/*
 * 页面从磁盘换到内存
 */ 
vmmu_swapon();

#endif


