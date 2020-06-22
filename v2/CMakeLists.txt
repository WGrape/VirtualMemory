cmake_minimum_required(VERSION 3.1.0)
project(VirtualMemory C)
set(CMAKE_C_STANDARD 99)

# 使用此配置头文件，头文件不用再写成 "../../../" 这样丑陋的路径了
include_directories(src)

# 设置目录变量
set(DIR_PUBLIC_INCLUDE src/include)
set(DIR_PUBLIC_MODULE ./src)

# 批量设置需要编译的文件
file(GLOB FILE_PUBLIC_INCLUDE ${DIR_PUBLIC_INCLUDE}/*.h)

# 添加到编译列表
add_executable(main src/main.c

        ${FILE_PUBLIC_INCLUDE}

        ${DIR_PUBLIC_MODULE}/sys/sys.h
        ${DIR_PUBLIC_MODULE}/sys/sys.c

        ${DIR_PUBLIC_MODULE}/command/command.h
        ${DIR_PUBLIC_MODULE}/command/command.c

        ${DIR_PUBLIC_MODULE}/boot/boot.h
        ${DIR_PUBLIC_MODULE}/boot/boot.c

        ${DIR_PUBLIC_MODULE}/mmu/mmu.h
        ${DIR_PUBLIC_MODULE}/mmu/mmu.c
        ${DIR_PUBLIC_MODULE}/mmu/tlb.h
        ${DIR_PUBLIC_MODULE}/mmu/tlb.c

        ${DIR_PUBLIC_MODULE}/pmu/pmu.h
        ${DIR_PUBLIC_MODULE}/pmu/pmu.c

        ${DIR_PUBLIC_MODULE}/sched/sched.h
        ${DIR_PUBLIC_MODULE}/sched/sched.c

        ${DIR_PUBLIC_MODULE}/ui/ui.h
        ${DIR_PUBLIC_MODULE}/ui/ui.c

        ${DIR_PUBLIC_MODULE}/vmmu/vmmu.h
        ${DIR_PUBLIC_MODULE}/vmmu/vmmu.c
)


