//
// Created by Gintoki-97 on 2019-05-04.
//

#include <stdio.h>
#include <stdlib.h>

#include "a.seqlist.cpp"

/**
 * Question:
 * - 设计一个搞笑算法，将顺序表的所有元素就地逆置，算法空间复杂度为 O(1)；
 **/
void reverseSeqList(SeqList* list) {

    /*
     * 思路：
     * 遍历顺序表中一半的元素，将第 i 个元素与第倒数第 i 个元素的
     * 值对调，无需额外的存储空间，虽然时间复杂度为 O(n)，但因为只
     * 遍历 length / 2 个元素，所以还算较为省时；
     */

    if (list == nullptr || list->length <= 1) {
        return;
    }

    // 1. 计算待遍历的顺序表元素个数
    int limit = list->length / 2;

    // 2. 开始逆置
    for (int i = 0; i < limit; i++) {
        int tmp = list->data[i];
        list->data[i] = list->data[list->length - i - 1];
        list->data[list->length - i - 1] = tmp;
    }
}

int main() {
    SeqList* list = generateSeqList(11);
    printList(list);
    reverseSeqList(list);
    printList(list);
    return 1;
}