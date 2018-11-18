// 内存中只存放 int 数据( process_id )

// 分配内存
int* mmu_alloc(){

	return (int*)malloc(sizeof(int)*1000);
}

// 收回内存
void mmu_collec(int *p){

	free(p);
}

// 载入一个新的进程
void mmu_load_process(Process process){

}
