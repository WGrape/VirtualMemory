#include <stdio.h>
#include <stdlib.h>
#include "command.h"

void command_init() {

}

int command_input(unsigned int type, void *input) {
    fgets((char *) input, INPUT_SIZE, stdin);

    if (INPUT_INT == type) {
        char *ptr;
        return (int)strtol(input, &ptr, 10);
    }
    return 0;
}

void command_action() {

}

void command_output() {

}

void command_exit() {

}

void command_kill() {

}