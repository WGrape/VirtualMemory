#ifndef INCLUDE_CONST_H
#define INCLUDE_CONST_H

/*
 * 枚举虚拟储存器菜单选项
 */
enum mmu_op {
    MENU_OP_NEW = 1, // 创建进程
    MENU_OP_KILL, // 中止进程
    MENU_OP_PRINT, // 打印出所有的进程(进程状态信息、虚存信息、物理内存信息)
    MENU_OP_DETAIL, // 打印当前某进程的详细信息
    MENU_OP_SCHED, // 打印当前的调度信息
    MENU_OP_QUIT, // 退出
};

/*
 * 枚举命令行交互状态
 */
enum interaction_st {
    INTERACTION_ST_CONTD = 1, // 继续当前交互
    INTERACTION_ST_QUIT, // 退出当前交互
};

/*
 * 定义最长长度
 * STR_LEN_30: 30字节长字符串
 * STR_LEN_100: 100字节长字符串
*/
#define STR_LEN_30 30
#define STR_LEN_100 100

/*
 * 定义响应码
 * RES_OK 成功: 0
 * RES_ERROR 失败: 1
 * RES_EXCEPTION 意外错误: -1
*/
#define RES_OK 0
#define RES_ERROR 1
#define RES_EXCEPTION -1

/*
 * 定义颜色类型
*/
#define T_COLOR_NONE "\033[0m"
#define T_COLOR_BLACK "\033[0;30m"
#define T_COLOR_RED "\033[0;31m"
#define T_COLOR_GREEN "\033[0;32m"
#define T_COLOR_ORANGE "\033[0;33m"
#define T_COLOR_BLUE "\033[0;34m"
#define T_COLOR_PURPLE "\033[0;35m"
#define T_COLOR_CYAN "\033[0;36m"
#define T_COLOR_LIGHT_GRAY "\033[0;37m"
#define T_COLOR_DARK_GRAY "\033[1;30m"
#define T_COLOR_LIGHT_RED "\033[1;31m"
#define T_COLOR_LIGHT_GREEN "\033[1;32m"
#define T_COLOR_YELLOW "\033[1;33m"
#define T_COLOR_LIGHT_BLUE "\033[1;34m"
#define T_COLOR_LIGHT_PURPLE "\033[1;35m"
#define T_COLOR_LIGHT_CYAN "\033[1;36m"
#define T_COLOR_WHITE "\033[1;37m"

#endif