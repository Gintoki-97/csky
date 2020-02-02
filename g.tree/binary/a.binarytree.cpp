#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <random>

#include "../z.common/utils.random.cpp"

typedef int ElementType;
typedef struct BTNode {
    ElementType data;            // 数据域
    struct BTNode *left, *right; // 左右孩子结点
} BTNode, *BTree;

