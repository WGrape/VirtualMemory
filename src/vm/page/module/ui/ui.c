#include<stdio.h>
#include <module/system/system.h>

static void ui_print_logo(){

	system_console_set_color(10);
	printf("____   ____.__         __               .__       _____                                       ._.\n"
		   "\\   \\ /   /|__|_______/  |_ __ _______  |  |     /     \\   ____   _____   ___________ ___.__. | |\n"
		   " \\   Y   / |  \\_  __ \\   __\\  |  \\__  \\ |  |    /  \\ /  \\_/ __ \\ /     \\ /  _ \\_  __ <   |  | | |\n"
		   "  \\     /  |  ||  | \\/|  | |  |  // __ \\|  |__ /    Y    \\  ___/|  Y Y  (  <_> )  | \\/\\___  |  \\|\n"
		   "   \\___/   |__||__|   |__| |____/(____  /____/ \\____|__  /\\___  >__|_|  /\\____/|__|   / ____|  __\n"
		   "                                      \\/               \\/     \\/      \\/              \\/       \\/");
	printf("\n");
	system_console_set_color(15);
}

static void ui_print_wait_for_input(){

	printf("> enter : ");
}

void ui_print_launch_view(){

	ui_print_logo();
	printf("Choose the different types of virtual memory\n");
	printf("---------------------------------------------------\n");
	printf("| 1(Page) | 2(Segment) | 3(SegmentPage) | 4(Quit) |\n");
	printf("---------------------------------------------------\n");
	ui_print_wait_for_input();
}

void ui_print_quit_view(){

	system_console_set_color(10);
	printf("__________                ._.\n"
		   "\\______   \\___.__. ____   | |\n"
		   " |    |  _<   |  |/ __ \\  | |\n"
		   " |    |   \\\\___  \\  ___/   \\|\n"
		   " |______  // ____|\\___  >  __\n"
		   "        \\/ \\/         \\/   \\/");
	system_console_set_color(15);
}

// 打印出欢迎语
void ui_print_vm_welcome_view(){

	system_console_set_color(2);
	printf("Page Virtual Memory Init Successfully !\n");
	system_console_set_color(15);
}

// 打印出菜单
void ui_print_vm_menu_view(){

	printf("\nServices for you to choose\n");
	printf("----------------------------------\n");
	printf("| 1 | New Process                |\n");
	printf("| 2 | Halt Process               |\n");
	printf("| 3 | Print All Processes        |\n");
	printf("| 4 | Print All Page Table Items |\n");
	printf("| 5 | Exit                       |\n");
	printf("----------------------------------\n");
	ui_print_wait_for_input();
}

// 打印出操作成功视图
void ui_print_operate_success(){

	system_console_set_color(2);
	printf("Operation Successfully !\n");
	system_console_set_color(15);
}

// 打印出错误视图
void ui_print_error_view(char *msg){

	system_console_set_color(2);
	printf(">>>>>>>>>>>>>>>>>>>>> ERROR ! <<<<<<<<<<<<<<<<<<<<<<\n");
	printf("msg : %s\n", msg);
	system_console_set_color(12);
}

// 打印出这个功能在下个更新中才实现
void ui_printf_it_is_todo(){

	system_console_set_color(2);
	printf("Sorry, this will be developed in the next update\n.");
	system_console_set_color(15);
}

