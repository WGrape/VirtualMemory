#include<stdio.h>

// 打印出欢迎语
void ui_print_welcome(int vm_type){

	if(vm_type==VM_TYPE_PAGE){

		printf("Page Virtual Memory Init Successfully !");
	}else if(vm_type==VM_TYPE_SEGMENT){

		printf("Segment Virtual Memory Init Successfully !");
	}else{

		printf("Segment-Page Virtual Memory Init Successfully !");
	}
}

// 打印出菜单
void ui_print_menu(){

	printf("Services for you to choose\n1(Print All Proccesses) 2(New Process) 3(Destroy Process)");
}

