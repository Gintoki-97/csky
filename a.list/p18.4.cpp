//
// Created by Gintoki-97 on 2019-05-05.
//

#include <stdio.h>
#include <stdlib.h>

#include "a.seqlist.cpp"

/**
 * Question:
 * - 从顺序表中删除其值 x 在给定范围（s < x < t）之间的所有元素，如果 s 或 t 不合理
 *   或顺序表为空则给出错误信息并退出；
 **/
bool removeElements(SeqList* list, ElementType lower, ElementType upper) {

    /*
     * 思路：
     * 沿用 P18.3 中的思路，将所有值不在给定范围内的元素保留，值在给定范围的数据
     * 自动被覆盖掉；
     * 分析：
     * 需要一趟完整的遍历，时间复杂度 O(n)，空间复杂度 O(1)
     */

    if (list->length <= 0) {
        printf("Remove elements failed, the sequence list is empty.");
        return false;
    }

    if (lower > upper) {
        printf("Remove elements failed, the upper: %d and lower: %d limits are invalid.", upper, lower);
        return false;
    }

    int count = 0;
    for (int i = 0; i < list->length; i++) {
        if (list->data[i] <= lower || list->data[i] >= upper) {
            list->data[count] = list->data[i];
            count++;
        }
    }

    list->length = count;
    return true;
}

int main() {
    SeqList* list = generateSeqList(20);
    printList(list);
    if (removeElements(list, 5, 8)) {
        printList(list);
    }
    return 1;
}