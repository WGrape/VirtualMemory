#include <stdio.h>

int main(){

	int vm_type;
	Memory memory;

	while(1){

		// 分配内存
		memory.pr = mmu_alloc();

		// 打印启动画面
		ui_print_launch_view();

		// 选择使用不同的虚拟存储器
		scanf("%d",&vm_type);
		switch(vm_type){

			// 页式虚拟存储器
			case VM_TYPE_PAGE:
			page_vm_init(memory);break;

			// 段式虚拟存储器
			case VM_TYPE_SEGMENT:
			segment_vm_init(memory);break;

			// 段页式虚拟存储器
			case VM_TYPE_SEGMENT_PAGE:
			segment_page_vm_init(memory);break;

			// 退出
			default:
			break;
		}

		// 回收内存
		mmu_collec(memory.pr);
	}

	printf("\nBye\n");
	return 0;
}
