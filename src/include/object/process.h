#ifndef INCLUDE_OBJECT_PROCESS_H
#define INCLUDE_OBJECT_PROCESS_H

#include <include/define/constant.h>

// 模拟的进程结构
typedef struct{

	int process_id; // 进程 id

	char process_name[ PROCESS_LIMIT_NAME_MAX_LEN ]; // 进程 name
}Process;


#endif
