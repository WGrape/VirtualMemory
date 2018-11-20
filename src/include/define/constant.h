#ifndef INCLUDE_DEFINE_CONSTANT_H
#define INCLUDE_DEFINE_CONSTANT_H

#define MEMORY_UNIT_COUNT 1000 // 内存单元个数(每个单元是 int,只存放一个进程的 id) , 也是进程的最大个数
#define MEMORY_PAGE_SIZE 10 // 每一页有10个
#define MEMORY_PAGE_COUNT 100 // 一共有100页


//#define PROCESS_NAME_MAX_LEN 30; // 进程名称的最大长度
typedef enum{

    PROCESS_LIMIT_NAME_MAX_LEN = 30,
    PROCESS_LIMIT_EXTRA_MAX_LEN = 100

}PROCESS_LIMIT;



typedef enum{

    VM_TYPE_PAGE = 1,
    VM_TYPE_SEGMENT,
    VM_TYPE_SEGMENT_PAGE
}VM_TYPE;
// #define VM_TYPE_PAGE 1; // 虚拟存储器类型 : 页式虚拟存储器
// #define VM_TYPE_SEGMENT 2; // 虚拟存储器类型 : 段式虚拟存储器
// #define VM_TYPE_SEGMENT_PAGE 3; // 虚拟存储器类型 : 段页式虚拟存储器


#endif