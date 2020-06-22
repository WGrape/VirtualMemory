#ifndef MODULE_UI_H
#define MODULE_UI_H

/*
 * 对外部暴露的操作
 */

/*
 * 展示启动视图
 */
extern void ui_show_launch();

/*
 * 展示菜单视图
 */
extern void ui_show_menu();

/*
 * 展示退出视图
 */
extern void ui_show_quit();

/*
 * 展示成功视图
 */
extern void ui_show_success();

/*
 * 展示错误视图
 */
extern void ui_show_error(char *msg);

#endif