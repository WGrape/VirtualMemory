#include <stdio.h>
#include <include/define/rescode.h>
#include <vm/page/module/ui/ui.h>
#include <include/define/constant.h>
#include <vm/page/module/init/init.h>

int main(){

	int quit = 0;
	int vm_type;

	while( !quit){

		// 打印启动画面
		ui_print_launch_view();

		// 选择使用不同的虚拟存储器
		scanf("%d",&vm_type);
		switch(vm_type){

			// 页式虚拟存储器
			case VM_TYPE_PAGE:
			page_vm_init();
			break;

			// 段式虚拟存储器
			case VM_TYPE_SEGMENT:
			// segment_vm_init();break;

			// 段页式虚拟存储器
			case VM_TYPE_SEGMENT_PAGE:
			// segment_page_vm_init();break;

			// 退出
			default: quit=1;break;
		}
	}

	printf("\nBye\n");
	return 0;
}
