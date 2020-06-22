#include<stdio.h>
#include "ui.h"

/*
 * 设置视图的颜色基值
 */
void ui_set_color(unsigned short color_index);

void ui_show_logo();

void ui_show_input();

void ui_set_color(unsigned short color_index) {

#if _WIN32
    // 控制Windows平台颜色输出
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color_index);
#elif __linux__
    // 控制Linux平台颜色输出
#else
    // 不使用颜色输出
#endif
}

void ui_show_logo() {

    ui_set_color(10);
    printf("____   ____.__         __               .__       _____                                       ._.\n"
           "\\   \\ /   /|__|_______/  |_ __ _______  |  |     /     \\   ____   _____   ___________ ___.__. | |\n"
           " \\   Y   / |  \\_  __ \\   __\\  |  \\__  \\ |  |    /  \\ /  \\_/ __ \\ /     \\ /  _ \\_  __ <   |  | | |\n"
           "  \\     /  |  ||  | \\/|  | |  |  // __ \\|  |__ /    Y    \\  ___/|  Y Y  (  <_> )  | \\/\\___  |  \\|\n"
           "   \\___/   |__||__|   |__| |____/(____  /____/ \\____|__  /\\___  >__|_|  /\\____/|__|   / ____|  __\n"
           "                                      \\/               \\/     \\/      \\/              \\/       \\/");
    printf("\n");
    ui_set_color(15);
}

void ui_show_launch() {

    ui_show_logo();
    printf("Welcome to virtual memory\n");
}

void ui_show_input() {

    printf("> enter : ");
}

void ui_show_menu() {

    printf("Menu for you to choose\n");
    printf("----------------------------------\n");
    printf("| 1 | New    Process              |\n");
    printf("| 2 | Use    Process              |\n");
    printf("| 3 | Detail Process              |\n");
    printf("| 4 | Quit   Process              |\n");
    printf("| 5 | Kill   Process              |\n");
    printf("| 6 | Print  Processes            |\n");
    printf("| 7 | Print  Schedule             |\n");
    printf("| 8 | Exit                        |\n");
    printf("----------------------------------\n");
    ui_show_input();
}

void ui_show_quit() {

    ui_set_color(10);
    printf("__________                ._.\n"
           "\\______   \\___.__. ____   | |\n"
           " |    |  _<   |  |/ __ \\  | |\n"
           " |    |   \\\\___  \\  ___/   \\|\n"
           " |______  // ____|\\___  >  __\n"
           "        \\/ \\/         \\/   \\/");
    ui_set_color(15);
}

void ui_show_success() {

    ui_set_color(2);
    printf("Operation Successfully !\n");
    ui_set_color(15);
}

void ui_show_error(char *msg) {

    ui_set_color(2);
    printf(">>>>>>>>>>>>>>>>>>>>> ERROR ! <<<<<<<<<<<<<<<<<<<<<<\n");
    printf("msg : %s\n", msg);
    ui_set_color(12);
}