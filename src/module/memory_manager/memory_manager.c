// 内存中只存放 int 数据( process_id )

// 分配内存
int* memory_manager_alloc(){

	return (int*)malloc(sizeof(int)*1000);
}

// 收回内存
void memory_manager_collec(int *p){

	free(p);
}
