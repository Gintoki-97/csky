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
    srand((unsigned int) (time(nullptr)));
}

/**
 * 生成带头结点的指定长度的单链表，使用头插法将随机生成的元素
 * 插入到链表中；
 *
 * @param len 链表的长度（不包含头结点）
 * @return 生成的链表
 */
LinkList generateListWithHeadNode(int len) {

    // 更新随机数种子
    updateRandomSeed();
    
    // 初始化头结点
    auto list = (LinkList) malloc(sizeof(LinkNode));
    list->data = -1;
    list->next = nullptr;

    // 生成指定数量的结点
    for (int i = 0; i < len; i++) {
        auto *node = (LinkNode*) malloc(sizeof(LinkNode));
        node->data = rand() % 10 + 1;
        node->next = list->next;
        list->next = node;
    }

    return list;
}

/**
 * 获取链表中第 index 个结点，如果 index 无效或未找到，
 * 则返回 NULL，否则返回该结点的引用。
 *
 * @param list 待查询的链表
 * @param index 需要查询的元素下标，从 1 开始计
 * @return 指定下标对应的结点指针
 */
LinkNode* get(LinkList &list, int index) {


    printf("Start to find the %dth node => ", index);

    LinkNode *p = list;
    int count = 0;

    while (p != nullptr && count != index) {
        count++;
        p = p->next;
    }

    if (count != index) {
        p = nullptr;
    }

    printf("Look up end, the value is: %d\n", p == nullptr ? NULL : p->data);
    return p;
}

/**
 * 打印给定的链表
 **/
void printList(LinkList list) {

    printf("LinkList: [");

    for (LinkNode *p = list; p != nullptr; p = p->next) {
        printf("%d", p->data);
        if (p->next != nullptr) {
            printf(" -> ");
        }
    }

    printf("]\n");
}