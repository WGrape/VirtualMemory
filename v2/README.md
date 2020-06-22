# VirtualMemory
计算机组成原理中虚拟存储器的实现（A Virtual Memory Implementation In Computer Organization）

## 开始
<img src="./extra/images/logo.gif" width="85%">

项目使用C语言开发，通过自定义内存管理，实现分页式虚拟存储器，完成用户程序在虚存中的载入、置换、以及进程间保护等基本功能。
1. git clone项目
2. 编译源码 src/main.c 文件运行
3. 按照cli提示操作，开始模拟虚存内部操作

## 概述

虚拟存储器将主存和辅存的地址空间统一编址，形成一个庞大的地址空间，在这个空间内，用户可以自由编程，而不必在乎实际的主存容量和程序在主存中实际的存放位置。

## 基本架构

![avatar](./extra/images/architecture.png)


