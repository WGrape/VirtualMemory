#ifndef MODULE_PMU_H
#define MODULE_PMU_H

/*
 * PCB进程链结点
 * 管理和控制进程, 类似Linux中的task_struct, 即进程描述符
 */
struct task_struct {

    // 进程描述
    int pid; // 进程id
    char p_name[STR_LEN_30]; // 进程的 name
    char p_extra[STR_LEN_100]; // 进程的 extra 信息

    // 进程状态
    volatile int state; // -1 unrunnable, 0 runnable, >0 stopped
    int signal;
    struct task_struct *next_task, *prev_task;

    // 进程调度描述
    int slice; // 时间片
    int priority; // 优先级

    // 进程内存描述
    struct mm_struct *mm;

    // 双向链表
    struct task_struct *pre;
    struct task_struct *next;
};

/*
 * 使用Linux标准流程创建进程: fork + exec
 */ 

/*
 * 复制父进程内存信息
 * 然后创建子进程
 */ 
void pmu_fork();

/*
 * 执行子进程代码
 * 并用子进程的内存信息进行覆盖
 */ 
void pmu_exec();

#endif
