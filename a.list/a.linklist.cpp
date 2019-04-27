#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <random>

// Typedef
typedef int ElementType;
typedef struct LinkNode {
    ElementType data;
    struct LinkNode *next;
} LinkNode, *LinkList;

/**
 * 设置随机数种子为当前系统时间
 **/
void updateRandomSeed() {
    srand((unsigned int) (time(NULL)));
}

LinkList generateListWithHeadNode(int len) {

    // 更新随机数种子
    updateRandomSeed();
    
    // 初始化头结点
    LinkList list = (LinkList) malloc(sizeof(LinkNode));
    list->data = -1;
    list->next = NULL;

    // 生成指定数量的结点
    for (int i = 0; i < len; i++) {
        LinkNode *node = (LinkNode*) malloc(sizeof(LinkNode));
        node->data = rand();
        node->next = list->next;
        list->next = node;
    }

    return list;
}

/**
 * 打印给定的链表
 **/
void printList(LinkList list) {

    printf("LinkList: [");


    for (LinkNode *p = list; p != NULL; p = p->next) {
        printf("%d", p->data);
        if (p->next != NULL) {
            printf(" -> ");
        }
    }

    printf("]\n");
}