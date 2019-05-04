//
// Created by Gintoki-97 on 2019-05-04.
//

#include <stdio.h>
#include <stdlib.h>

#include "a.seqlist.cpp"

/**
 * Question:
 * - 设计一个时间复杂度为 O(n)，空间复杂度为 O(1) 的算法，该算法可以删除
 *   顺序表中所有值为 x 的数据元素；
 **/
void removeElement(SeqList* list, ElementType e) {

    /*
     * 思路：
     * 1. 传入的顺序表中的值分为两部分来考虑：等于 x 的和不等于 x 的这两部分；
     * 2. 对于需要返回的顺序表，其中只包含第二部分（不等于 x 的数据元素），下标 0 对应第 1 个不等于 x 的数据元素，
     *    下标 1 对应第 2 个不等于 x 的数据元素，... ，下标 i 对应第 i + 1 个不等于 x 的数据元素；
     * 3. 因此可以从头开始遍历顺序表中的每个元素，记录不等于 x 的元素个数，并将其覆盖到原顺序表中的指定位置；相当于
     *    依次拿每个不为 x 的数据元素重新为原顺序表赋值；
     */

    // 1. 记录值不为 x 的元素个数
    int count = 0;

    // 2. 遍历顺序表，将不为 x 的数据元素覆盖到指定位置
    for (int i = 0; i < list->length; i++) {
        if (list->data[i] != e) {
            list->data[count] = list->data[i];
            count++;
        }
    }

    // 3. 为顺序表的长度重新赋值，新的长度即为值不为 x 的数据元素的个数
    list->length = count;
}

int main() {
    SeqList* list = generateSeqList(20);
    printList(list);
    removeElement(list, 8);
    printList(list);
    return 1;
}