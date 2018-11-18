#ifndef INCLUDE_OBJECT_PROCESS_H
#define INCLUDE_OBJECT_PROCESS_H


typedef struct{

	int process_id; // 进程 id
	char process_name[PROCESS_NAME_LEN]; // 进程 name
}Process;


#endif
