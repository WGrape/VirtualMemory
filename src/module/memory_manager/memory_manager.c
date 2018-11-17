// 分配内存
char* alloc_memory(){

	return (char*)malloc(sizeof(char)*1000);
}

// 收回内存
void collec_memory(char *p){

	free(p);
}
