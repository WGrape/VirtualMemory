// 分配内存
char* memory_manager_alloc(){

	return (char*)malloc(sizeof(char)*1000);
}

// 收回内存
void memory_manager_collec(char *p){

	free(p);
}
