#include <stdio.h>
#include <stdlib.h>

#include "b.linklist.cpp"

/**
 * Question:
 * - 设计一个递归算法，删除不带头结点的单链表 L 中所有值为 x 的结点；
 **/
void removeElement(LinkList &list, ElementType x) {

    // 如果链表为空，直接返回
    if (list == NULL) {
        return;
    }

    // 如果当前 list 指向的第一个结点为 x，则删除该结点
    if (list->data == x) {
        LinkNode *p = list; 
        free(p);
    }
    
    // 递归
    removeElement(list->next, x);
}

int main() {

    LinkList list = generateListWithHeadNode(8);
    printList(list);
    removeElement(list, 30);
    printList(list);
}