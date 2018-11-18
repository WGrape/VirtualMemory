#ifndef INCLUDE_OBJECT_PROCESS_H
#define INCLUDE_OBJECT_PROCESS_H


typedef struct{

	int process_id; // 进程 id
	char process_name[PROCESS_NAME_LEN]; // 进程 name
	// char process_desc[100]; // 进程描述

	int *virtual_address; // 进程的地址
	int *physical_address; // 进的物理地址(实地址)

}Process;


#endif
