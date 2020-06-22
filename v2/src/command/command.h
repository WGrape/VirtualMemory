#ifndef MODULE_COMMAND_H
#define MODULE_COMMAND_H

#define INPUT_INT 0
#define INPUT_STR 1
#define INPUT_SIZE 30

/*
 * 初始化: 完成启动性工作
 */
extern void command_init();

/*
 * 输入行为: 对内的一致输入口
 */
extern int command_input(unsigned int type, void *input);

/*
 * 核心逻辑: 处理输入, 生成输出数据
 */
extern void command_action();

/*
 * 输出行为: 对外的一致输出口
 */
extern void command_output();

/*
 * 退出行为: 程序正常退出时, 完成正常流程性的收尾工作
 */
extern void command_exit();

/*
 * 终止行为: 在用户手动Kill或者程序内部异常退出时，完成清理性的工作
 */
extern void command_kill();

#endif