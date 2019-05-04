#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <random>

#include "../z.common/utils.random.cpp"

/*
 * 顺序表的初始分配方式有两种：静态分配和动态分配
 * 1. 静态分配
 * typedef struct {
 *     ElementType data[MaxSize];
 *     int length;
 * }
 * 静态分配的初始空间是事先固定下来的，无法改变大小，一旦元素超限，就会溢出；
 *
 * 2. 动态分配
 * #define InitSize 100
 * typedef struct {
 *     ElementType *data;
 *     int MaxSize, length;
 * }
 * 动态分配的空间可以在程序运行时确定
 * eg. L.data = (ElementType*) malloc(sizeof(ElementType) * InitSize);
 */

// Typedef
typedef int ElementType;
typedef struct {
    ElementType *data;
    int MaxSize, length;
} SeqList;

/**
 * <p>将给定的数据元素，插入到给定的顺序表的第 i 个位置中；</p>
 * <p>若 i 的位置不合法，返回 false，表示插入失败；否则将顺序表
 * 的第 i 个元素及其后面的所有元素后移一个位置，将新元素插入，并
 * 将顺序表长度自增 1，返回 true；</p>
 *
 * @param list 需要插入的顺序表
 * @param i    插入的位置，从 1 开始
 * @param e    待插入的数据元素
 * @return 是否插入成功
 */
bool listInsert(SeqList* list, int i, ElementType e) {

    // 1. 判断 i 的位置是否合法
    if (i < 1 || i > list->length + 1) {
        printf("Insert failed, the insert index: %d is invalid", i);
        return false;
    }

    // 2. 判断顺序表是否已满
    if (list->length >= list->MaxSize) {
        printf("Insert failed, the sequence list is full");
        return false;
    }

    // 3. 将第 i 个元素及其后面的所有元素后移
    for (int j = list->length; j > i; j--) {
        list->data[j] = list->data[j - 1];
    }

    list->data[i - 1] = e;
    list->length++;
    return true;
}

/**
 * 删除顺序表中第 i(1 <= i <= length) 个位置的元素，成功则返回 true，
 * 并将被删除的元素用引用变量 e 返回；否则返回 false；
 */
bool listDelete(SeqList* list, int i, ElementType &e) {

    // 1. 判断 i 的值是否合法
    if (i < 1 || i > list->length) {
        printf("Delete element failed, the insert index: %d is invalid", i);
        return false;
    }

    // 2. 将待删除的元素的值赋给 e
    e = list->data[i - 1];

    // 3. 将第 i 个位置后的元素前移
    for (int j = i; j < list->length; j++) {
        list->data[j - 1] = list->data[j];
    }

    list->length--;
    return true;
}

/**
 * 在顺序表中定位给定的元素，返回其位序（1 ~ length），如果找不到返回 0；
 */
int locateElement(SeqList* list, ElementType e) {

    for (int i = 0; i < list->length; i++) {
        if (list->data[i] == e) {
            return i + 1;
        }
    }

    return 0;
}

/**
 * 判断给定的顺序表是否为空，返回 true 则表示顺序表为空；
 */
bool isEmpty(SeqList* &list) {
    return list->length == 0;
}

/**
 * 生成指定长度的顺序表，值为随机数；
 */
SeqList* generateSeqList(int len) {

    auto seqList = new SeqList();
    seqList->data = new ElementType[len];
    seqList->length = len;

    for (int i = 0; i < len; i++) {
        seqList->data[i] = randomInt(20);
    }

    return seqList;
}

/**
 * 打印给定的顺序表
 **/
void printList(SeqList* list) {

    printf("SeqList: [");

    for (int i = 0; i < list->length; i++) {
        printf("%d", list->data[i]);
        if (i != (list->length - 1)) {
            printf(" -> ");
        }
    }

    printf("]\n");
}