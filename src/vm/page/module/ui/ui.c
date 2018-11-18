#include<stdio.h>

void ui_print_launch_view(){

	printf("Choose the different types of virtual memory\n1(Page) 2(Segment) 3(SegmentPage) 4(Quit) : ");	
}

// 打印出欢迎语
void ui_print_vm_welcome(int vm_type){

	if(vm_type==VM_TYPE_PAGE){

		printf("Page Virtual Memory Init Successfully !");
	}else if(vm_type==VM_TYPE_SEGMENT){

		printf("Segment Virtual Memory Init Successfully !");
	}else{

		printf("Segment-Page Virtual Memory Init Successfully !");
	}
}

// 打印出菜单
void ui_print_vm_menu(){

	printf("Services for you to choose\n1(Print All Proccesses) 2(New Process) 3(Destroy Process) 4(Exit)");
}

