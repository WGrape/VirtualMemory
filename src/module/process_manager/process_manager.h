#ifndef MODULE_PROCESS_MANAGER_H
#define MODULE_PROCESS_MANAGER_H

extern void process_manager_new(Process process);

extern void process_manager_halt(int process_id);

extern void process_manager_get_all();

extern void process_manager_print_all();

#endif


