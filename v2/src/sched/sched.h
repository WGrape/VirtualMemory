#ifndef MODULE_SCHED_H
#define MODULE_SCHED_H

/*
 * 定义1秒钟1次
 */ 
#define HZ 1

/*
 * 定义进程6种状态
 */
#define TASK_RUNNING 0 // 可执行态:运行或将要运行
#define TASK_INTERRUPTIBLE 1 // 休眠状态:可中断
#define TASK_UNINTERRUPTIBLE 2 // 休眠状态:不可中断
#define TASK_ZOMBIE 3 // 僵死状态:待父进程处理
#define TASK_STOPPED 4 // 暂停状态:可接收信号唤醒
#define TASK_SWAPPING 5 // 换页状态:页面正在换入换出

/*
 * 初始化调度器
 */ 
extern void sched_init();

/*
 * 不可中断休眠
 * 状态标记为TASK_UNINTERRUPTIBLE
 * 进程持续休眠, 不再响应外界的唤醒信号, 直到睡眠时间结束
 */ 
extern void sched_sleep();

/*
 * 可中断休眠
 * 状态标记为TASK_INTERRUPTIBLE
 * 进程持续休眠, 直到接收到唤醒进程的信号
 */ 
extern void sched_sleep_interruptible();

/*
 * 唤醒不可中断休眠的单一进程
 */ 
extern void sched_wake_up();

/*
 * 唤醒不可中断休眠队列中的所有进程
 */ 
extern void sched_wake_up_all();

/*
 * 唤醒可中断休眠的单一进程
 */ 
extern void sched_wake_up_interruptible();

/*
 * 唤醒可中断休眠队列中的所有进程
 */
extern void sched_wake_up_interruptible_all();

/*
 * 发送信号到进程
 */ 
extern int sched_send_sig(unsigned long sig);

/*
 * 暂停进程
 * 状态标记为TASK_STOPPED
 * 接收SIGSTOP信号后处于挂起状态, 直到接收SIGCONT信号
 */ 
extern int sched_pause();

/*
 * 中止进程
 * 状态标记为TASK_ZOMBIE
 */
extern int sched_zombie();

#endif
