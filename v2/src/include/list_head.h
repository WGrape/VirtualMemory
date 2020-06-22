#ifndef INCLUDE_LIST_HEAD_H
#define INCLUDE_LIST_HEAD_H

/*
 * list head 即链表的表头结构
 * 链表包括表头域(指针域)和数据域, Linux的设计思想是拆分表头域和数据域, 表头域用双向循环链表结构存储
 * 所以head只是表示表头域的意思, 并不是链表的头结点, 这点一定要注意, 否则看不懂代码
 */
typedef struct list_head {
    struct list_head *next, *prev;
} list_head;

#define LIST_POISON1  ((void *) 0x00100100)
#define LIST_POISON2  ((void *) 0x00200200)

/**
 * 初始化链表
 * @param list
 */
void init_list_head(list_head *list) {
    list->next = list;
    list->prev = list;
}

/**
 * 通用操作: 在表头域尾添加一个新的表头域
 * @param new
 * @param prev
 * @param next
 */
void __list_add(list_head *new, list_head *prev, list_head *next) {

    next->prev = new;
    new->next = next;
    new->prev = prev;
    prev->next = new;
}

/**
 * 在表头域尾添加一个新的表头域
 * @param new
 * @param head
 */
void list_add(list_head *new, list_head *head) {
    __list_add(new, head, head->next);
}

/**
 * 在表头域前添加一个新的表头域
 * @param new
 * @param head
 */
void list_add_tail(list_head *new, list_head *head) {
    __list_add(new, head->prev, head);
}

/**
 * 通用操作: 删除当前的节点
 * @param prev
 * @param next
 */
void __list_del(list_head *prev, list_head *next) {
    next->prev = prev;
    prev->next = next;
}

void list_del(list_head *entry) {
    __list_del(entry->prev, entry->next);
    entry->next = LIST_POISON1;
    entry->prev = LIST_POISON2;
}

void list_del_init(list_head *entry){
    __list_del(entry->prev, entry->next);
    init_list_head(entry);
}

// https://blog.csdn.net/qq_33160790/article/details/69063774

#endif
