#include <stdio.h>
#include <vm/page/module/ui/ui.h>
#include <stdlib.h>
#include <string.h>

void system_exit(char *msg){

    if(0==strcmp(msg,"")){

        msg = "msg is nothing";
    }

    ui_print_error_view(msg);
    exit(1);
}

void system_debug(){

    printf("-----------debug-----------");
}
