#include <stdio.h>
#include <include/const.h>
#include <boot/boot.h>
#include <ui/ui.h>
#include <command/command.h>

int main() {

    boot_strap();

    // 打印启动画面
    ui_show_launch();

    // 进入交互环境
    int st = INTERACTION_ST_CONTD;
    while (INTERACTION_ST_QUIT != st) {

        // 打印菜单画面
        ui_show_menu();
        st = command_input(INPUT_INT, &st);

        switch (st) {

            case MENU_OP_NEW:
                break;

            case MENU_OP_DETAIL:
                break;

            case MENU_OP_KILL:
                break;

            case MENU_OP_PRINT:
                break;

            case MENU_OP_SCHED:
                break;

            case MENU_OP_QUIT:
            default:
                st = INTERACTION_ST_QUIT;
                break;
        }
    }

    ui_show_quit();
    return RES_OK;
}
