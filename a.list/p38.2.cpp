#include <stdio.h>
#include <stdlib.h>

#include "b.linklist.cpp"

/**
 * Question:
 * - 在带头结点的单链表 L 中，删除所有值为 x 的结点，并释放其空间，假设值为 x 的结点不唯一；
 **/
void removeElement(LinkList &list, ElementType x) {

    /*
     * 思路：
     * 1. 设置两个指针：p 指向当前元素，q 指向 p 的前驱结点；
     * 2. 如果 p 的值为 x，则删除 p 结点并将 p 后移；
     * 3. 如果 p 的值不为 x，则 p、q 同步后移；
     **/

    printf("Start remove the element: %d => ", x);

    // 如果链表为空，直接返回
    if (list == nullptr) {
        return;
    }

    LinkNode *q = list;
    LinkNode *p = list->next;

    // 如果 p 的值为 x，则删除 p 结点并将 p 后移
    while (p != nullptr) {
        if (p->data == x) {
            LinkNode *r = p;
            q->next = p->next;
            p = p->next;
            free(r);
        } else {
            p = p->next;
            q = q->next;
        }
    }

    printf("Ending of the remove\n");
}

int main() {

    LinkList list = generateListWithHeadNode(20);
    printList(list);
    LinkNode *node = get(list, 3);
    removeElement(list, node->data);
    printList(list);
}