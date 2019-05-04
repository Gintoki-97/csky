//
// Created by Gintoki-97 on 2019-05-04.
//

#include <stdio.h>
#include <stdlib.h>

#include "a.seqlist.cpp"

/**
 * Question:
 * - 从顺序表中删除具有最小值的元素（假设唯一），并由函数返回被删除的元素的值；
 *   空出的位置由最后一个元素填补；若顺序表为空则显示出错信息并退出；
 **/
bool removeMinimum(SeqList *list, ElementType &e) {

    /*
    * 思路：
    * 设置一个整数记录最小值下标，遍历给定顺序表，依次与最小值比较；
    * 遍历完毕后将最小值元素的值记录下来，使用最后一个元素的值覆盖并返回记录的最小值；
    */

    if (isEmpty(list)) {
        printf("Remove the minimum element failed, the list is empty");
        return false;
    }

    // 1. 初始化最小值下标
    int index = 0;
    e = list->data[0];

    // 2. 遍历顺序表，比较、记录最小值
    for (int i = 1; i < list->length; i++) {
        if (list->data[i] < e) {
            index = i;
            e = list->data[i];
        }
    }

    // 3. 使用最后一个元素覆盖第 i 个元素
    list->data[index] = list->data[list->length - 1];
    list->length--;
    return true;
}

int main () {

    SeqList* list = generateSeqList(10);
    printList(list);

    ElementType a;
    removeMinimum(list, a);

    printList(list);
    printf("The removed minimum element: %d", a);

    return 1;
}