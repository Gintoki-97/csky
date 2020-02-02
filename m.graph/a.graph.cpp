//
// Created by Gintoki-97 on 2019-07-14.
//

#define MaxVertexNum 100

/*
 * 邻接矩阵
 */

typedef char VertexType;
typedef int EdgeType;

typedef struct {
    // 顶点表
    VertexType Vex[MaxVertexNum];
    // 边表
    EdgeType Edge[MaxVertexNum][MaxVertexNum];
    int vexNum, arcNum; // 图的顶点数 & 弧数
} MGraph;   // 邻接矩阵

/*
 * 邻接表
 */

typedef struct ArcNode {
    int adjVex;             // 该弧指向的顶点位置
    struct ArcNode *next;   // 指向下一条弧的指针
} ArcNode;  // 边表结点

typedef struct VNode {
    VertexType data;    // 顶点信息
    ArcNode *first;     // 指向第一条依附于该顶点的弧的指针
} VNode, AdjList[MaxVertexNum]; // 顶点表结点

typedef struct {
    AdjList vertices;   // 邻接表
    int vexNum, arcNum; // 图的顶点数和弧数
} ALGraph;  // 邻接表
