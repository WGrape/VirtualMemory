cmake_minimum_required(VERSION 3.1.0)
project(VirtualMemory C)

set(CMAKE_C_STANDARD 99)

# 使用此配置头文件，头文件不用再写成 "../../../" 这样丑陋的路径了
include_directories(../src)

# sherkd表示编译后的可执行文件名为 sherk
set(INCLUDE_DIR ./include)
set(VM_DIR ./vm)
add_executable(main ./main.c

        ${INCLUDE_DIR}/define/constant.h
        ${INCLUDE_DIR}/define/rescode.h

        ${INCLUDE_DIR}/object/Memory.h
        ${INCLUDE_DIR}/object/PCB.h
        ${INCLUDE_DIR}/object/PhysicalAddress.h
        ${INCLUDE_DIR}/object/Process.h
        ${INCLUDE_DIR}/object/ProcessLinkedNode.h
        ${INCLUDE_DIR}/object/VirtualAddress.h

        ${VM_DIR}/page/include/define/constant.h
        ${VM_DIR}/page/include/object/PageTable.h
        ${VM_DIR}/page/include/object/PageTableItemLinkedNode.h
        ${VM_DIR}/page/include/object/VMModel.h

        ${VM_DIR}/page/module/command/command.c
        ${VM_DIR}/page/module/command/command.h
        ${VM_DIR}/page/module/init/init.c
        ${VM_DIR}/page/module/init/init.h
        ${VM_DIR}/page/module/mmu/mmu.c
        ${VM_DIR}/page/module/mmu/mmu.h
        ${VM_DIR}/page/module/pmu/pmu.c
        ${VM_DIR}/page/module/pmu/pmu.h
        ${VM_DIR}/page/module/ui/ui.c
        ${VM_DIR}/page/module/ui/ui.h
        ${VM_DIR}/page/module/vmmu/vmmu.c
        ${VM_DIR}/page/module/vmmu/vmmu.h


        )

