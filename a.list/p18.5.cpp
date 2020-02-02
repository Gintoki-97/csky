//
// Created by Gintoki-97 on 2019-05-05.
//

#include <stdio.h>
#include <stdlib.h>

#include "a.seqlist.cpp"

/**
 * Question:
 * - 从有序顺序表中删除所有值重复的元素，使表中所有元素的值均不相同；
 **/
void distinctList(SeqList* list) {

    if (isEmpty(list)) {
        printf("The sequence list is empty.");
        return;
    }

    int i, j;

    for (i = 0, j = 1; j < list->length; i++) {

        while (list->data[j] == list->data[i]) {
            j++;
        }

        if (j - i > 1) {
            list->data[i + 1] = list->data[j];
        }

        j++;
    }

    list->length = i;
}

void testDistinctList() {
    SeqList* list = generateSeqList(20);
    printList(list);
    distinctList(list);
    printList(list);
}