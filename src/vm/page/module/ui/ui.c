#include<stdio.h>

static void ui_print_logo(){

	printf("____   ____.__         __               .__       _____                                       ._.\n"
		   "\\   \\ /   /|__|_______/  |_ __ _______  |  |     /     \\   ____   _____   ___________ ___.__. | |\n"
		   " \\   Y   / |  \\_  __ \\   __\\  |  \\__  \\ |  |    /  \\ /  \\_/ __ \\ /     \\ /  _ \\_  __ <   |  | | |\n"
		   "  \\     /  |  ||  | \\/|  | |  |  // __ \\|  |__ /    Y    \\  ___/|  Y Y  (  <_> )  | \\/\\___  |  \\|\n"
		   "   \\___/   |__||__|   |__| |____/(____  /____/ \\____|__  /\\___  >__|_|  /\\____/|__|   / ____|  __\n"
		   "                                      \\/               \\/     \\/      \\/              \\/       \\/");
}

static void ui_print_line(){

	printf("---------------------------------------------------\n");
}

static void ui_print_wait_for_input(){

	printf("> enter : ");
}

void ui_print_launch_view(){

	ui_print_logo();
	printf("\n\n");
	printf("Choose the different types of virtual memory\n");
	ui_print_line();
	printf("| 1(Page) | 2(Segment) | 3(SegmentPage) | 4(Quit) |\n");
	ui_print_line();
	ui_print_wait_for_input();
}

void ui_print_quit_view(){

	printf("__________                ._.\n"
		   "\\______   \\___.__. ____   | |\n"
		   " |    |  _<   |  |/ __ \\  | |\n"
		   " |    |   \\\\___  \\  ___/   \\|\n"
		   " |______  // ____|\\___  >  __\n"
		   "        \\/ \\/         \\/   \\/");
}

// 打印出欢迎语
void ui_print_vm_welcome_view(){

	printf("\nPage Virtual Memory Init Successfully !");
}

// 打印出菜单
void ui_print_vm_menu_view(){

	printf("\n\n");
	printf("Services for you to choose\n");
	ui_print_line();
	printf("| 1(Print All Proccesses) | 2(New Process) | 3(Destroy Process) | 4(Exit) |\n");
	ui_print_line();
	ui_print_wait_for_input();
}

