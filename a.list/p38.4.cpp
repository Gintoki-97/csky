//
// Created by Gintoki on 2019/4/28.
//

#include <stdio.h>
#include <stdlib.h>

#include "b.linklist.cpp"

/**
 * Question:
 * - 编写算法在带头结点的单链表中，删除一个最小值结点的高效算法（假设最小值结点唯一）；
 **/
void removeMinimum(LinkList &list) {

    /*
     * 思路：
     * 使用多个指针，保证一次遍历后，即可定位到最小元素及其前驱结点，
     * 这样的话删除操作只需要一次遍历即可完成；
     * 分析：
     * 为了找到最小的元素，需要完成一次全表扫描操作，时间复杂度为O(n)，空间复杂度O(1)，不需要辅助空间
     */

    // 判断链表指针(list)是否为空；是否是空表(list->next)
    if (list == nullptr || list->next == nullptr) {
        return;
    }

    // 指针 p 指向当前元素，q 指向 p 的前驱结点
    LinkNode *q = list->next;   // 指向头结点后第一个结点
    LinkNode *p = q->next;      // 指向头结点后第二个结点

    // 指针 n 指向目前的最小值结点，m 指向 n 的前驱结点
    LinkNode *m = q;
    LinkNode *n = p;

    // 如果链表中除头结点外只有一个结点
    if (list->next->next == nullptr) {
        list->next = nullptr;
        free(m);
        return;
    }

    while (p != nullptr) {

        // 判断最小值结点是否小于当前结点
        if (p->data < n->data) {
            n = p;
            m = q;
        }

        // p, q 同步后移
        p = p->next;
        q = q->next;
    }

    // 删除 m 的后继结点 n
    if (m != nullptr && n != nullptr) {
        m->next = n->next;
        free(n);
    }
}

int main() {

    LinkList list = generateListWithHeadNode(10);
    printList(list);
    removeMinimum(list);
    printList(list);

    return 0;
}