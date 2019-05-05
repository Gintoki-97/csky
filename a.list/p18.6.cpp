//
// Created by Gintoki-97 on 2019-05-05.
//

#include <stdio.h>
#include <stdlib.h>

#include "a.seqlist.cpp"

/**
 * Question:
 * - 将两个有序顺序表合并为一个新的有序的顺序表，并由函数返回合成的新的顺序表；
 **/
bool mergeList(SeqList* list1, SeqList* list2, SeqList* list) {

    if (list->length + list2->length > list->MaxSize) {
        printf("The size of two lists are too long for list");
        return false;
    }

    int i = 0, j = 0, k = 0;

    // 1. 将两个有序表中较短的那个先遍历完成
    while (i < list1->length && j < list2->length) {
        list->data[k++] = (list1->data[i] > list2->data[j] ? list1->data[i++] : list2->data[j++])
    }

    // 2. 将有序表中较长的那个顺序表剩余的元素添加到 list 中
    while (i < list1->length) {
        list->data[k++] = list1->data[i++];
    }
    while (j < list2->length) {
        list->data[k++] = list2->data[j++];
    }

    list->length = k;
    return true;
}