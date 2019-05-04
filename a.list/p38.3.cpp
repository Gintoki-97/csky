//
// Created by Gintoki on 2019/4/28.
//

#include <stdio.h>
#include <stdlib.h>

#include "b.linklist.cpp"

/**
 * Question:
 * - 对于一个带头结点的单链表，尝试逆序输出每个结点的值；
 **/
 void reversePrint(LinkList &list) {

     /*
      * 思路：
      * --
      * 1. 头结点不动，顺序遍历每个元素，使用头插法插入该头结点；
      * 2. 插入完成后，该链表即已被逆置；
      * --
      * 1. 递归调用打印方法，如果后继结点不为空，则递归打印后继结点；
      *
      * 分析：
      * m1: 时间复杂度O(n)，空间复杂度O(1)，性能略次与m2，链表会被逆置；
      * m2: 时间复杂度O(n)，空间复杂度O(n)，递归需要额外的栈空间，链表不会被逆置；
      *
      * 实现：
      * 此处使用 m2 实现，m1 放到 p38.5 中实现
      */

      if (list == nullptr) {
          return;
      }

      LinkNode *p = list;
      if (p->next != nullptr) {
          reversePrint(p->next);
      }

      printf("%d ", p->data);
 }

int main() {

    LinkList list = generateListWithHeadNode(10);
    printList(list);

    printf("Start to reverse print the list => \nLinkList: [");
    reversePrint(list);
    printf("]\n");
}