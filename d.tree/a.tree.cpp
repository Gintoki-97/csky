//
// Created by Gintoki on 2019/5/12.
//

#include <stdio.h>
#include <stdlib.h>


/**
 * 树的顺序存储结构：
 * ----
 * 1. 双亲表示法
 *
 * typedef char ElementType;
 * typedef struct TreeNode {
 *     ElementType data;
 *     int parent;
 * } TreeNode;
 *
 * #define MaxSize 100
 * typedef struct {
 *     TreeNode nodes[MaxSize]; // 结点数组
 *     int count;   // 结点数量
 * } Tree;
 *
 * ====================
 *
 * 树的链式存储
 * ----
 * 1. 孩子表示法
 *
 * typedef char ElementType;
 * typedef struct CNode {
 *     int child;           // 该子节点在表头数组（Tree.nodes）的下标
 *     struct CNode *next;  // 指向该结点的下一个孩子结点
 * } CNode, *Child;         // 孩子结点的数据类型
 *
 * typedef struct {
 *     ElementType data;    // 结点数据域
 *     Child firstChild;    // 指向该结点的第一个孩子结点
 * } TreeNode;
 *
 * #define MaxSize 100
 * typedef struct {
 *     TreeNode nodes[MaxSize]; // 结点数组，包含树中所有结点
 *     int count;   // 结点数量
 * } Tree;
 *
 * 2. 孩子兄弟表示法
 *
 * typedef char ElementType;
 * typedef struct CSNode {
 *     ElementType data;
 *     struct CSNode *leftChild, *rightChild;
 * } CSNode;
 */

typedef char ElementType;
typedef struct TreeNode {
    ElementType data;
    int parent;
} TreeNode;

#define MaxSize 100
typedef struct {
    TreeNode nodes[MaxSize]; // 结点数组
    int count;   // 结点数量
} Tree;

Tree createTree(Tree tree, int len) {

    // ~ 1.
    printf("Start the creation of tree (y/n): ");
    char command;
    scanf("%c", &command);

    // ~ 2.
    if (command == 'n') {
        printf("Exit the creation.\n");
        return tree;
    }

    // ~ 3.
    for (int i = 0; ; i++) {
        printf("Please type the %dth value of the node (exists when type 'n'): ", (i + 1));
        char val;
        scanf("%c", &val);
        if (val == 'n') {
            break;
        }

        TreeNode node = (TreeNode) malloc(sizeof(TreeNode));
        node.data = val;
        node.parent
    }

    return tree;
}