//
// Created by Gintoki on 2019/4/28.
//

#include <stdio.h>
#include <stdlib.h>

#include "./a.linklist.cpp"

/**
 * Question:
 * - 编写算法将带头结点的单链表就地逆置，辅助空间复杂度要求为O(1)；
 **/
void reverseLinkList(LinkList &list) {

    /*
     * 思路：
     * 头结点不动，顺序遍历每个元素，使用头插法将每个结点插入到链表中；
     * 原链表分为两部分，第一部分是原头结点，第二部分是头结点后的结点链表；
     * 分析：
     * 需要顺序扫描全表，并将每个结点做一次插入操作，时间复杂度O(n)，不需要额外的辅助空间，
     * 空间复杂度O(1)；
     */

    // 将链表分为两部分，头结点为第一部分；剩余为第二部分；
    // 指针 p 将始终指向二链表的第一个元素，q 指向 p 并将作为游标指针；
    LinkNode *p = list->next;
    LinkNode *q = p;
    // 指针 h 为一链表，并将一二两部分分开
    LinkNode *h = list;
    h->next = nullptr;

    // 将二链表中的每个结点使用头插法插入一链表
    while (q != nullptr) {
        // 指针 p 后移，指针 q 移出二链表
        p = p->next;
        // 将指针 q 插入到一链表
        q->next = h->next;
        h->next = q;
        // 指针 q 重新移到二链表首位
        q = p;
    }
}

int main() {

    LinkList list = generateListWithHeadNode(10);
    printList(list);
    reverseLinkList(list);
    printList(list);
}