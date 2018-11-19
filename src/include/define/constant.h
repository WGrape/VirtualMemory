#ifndef INCLUDE_DEFINE_CONSTANT_H
#define INCLUDE_DEFINE_CONSTANT_H

#define MEMORY_UNIT_COUNT 1000; // 内存单元个数(每个单元是 int,只存放一个进程的 id)
#define MEMORY_PAGE_SIZE 10 // 每一页有10个
#define MEMORY_PAGE_COUNT 100 // 一共有100页

#define VM_TYPE_PAGE 1; // 虚拟存储器类型 : 页式虚拟存储器
#define VM_TYPE_SEGMENT 2; // 虚拟存储器类型 : 段式虚拟存储器
#define VM_TYPE_SEGMENT_PAGE 3; // 虚拟存储器类型 : 段页式虚拟存储器

#define VM_MENU_OPTION_PRINT_ALL_PROCESSES 1; // 虚拟储存器菜单-打印出所有的进程
#define VM_MENU_OPTION_NEW_PROCESSES 2; // 虚拟储存器菜单-创建进程
#define VM_MENU_OPTION_HALT_PROCESSES 3; // 虚拟储存器菜单-中止进程


#define PROCESS_NAME_LEN 20; // 线程名称的长度
#define PROCESS_PROCESS_EXTRA_LEN_LEN 100; // 线程名称的长度

#endif