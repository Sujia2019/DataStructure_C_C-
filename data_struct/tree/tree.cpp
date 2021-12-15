#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int data;
}ElemType;

// 双亲表示法(顺序结构)
#define MAX_TREE_SIZE 100
typedef struct{
    ElemType data;
    int parent; // 双亲位置域
}PTNode;
typedef struct{
    PTNode nodes[MAX_TREE_SIZE];
    int n; // 结点数
}PTree;

//孩子表示法（顺序+链式）
struct CTNode
{
    int child; // 孩子结点在数组中的位置
    struct CTNode *next;
};
typedef struct{
    ElemType data;
    struct CTNode &firstChild;
}CTBox;
typedef struct{
    CTBox nodes[MAX_TREE_SIZE];
    int n, r; // 结点数和根的位置
}CTree;

// 孩子兄弟表示法（链式）
typedef struct CSNode{
    ElemType data;
    struct CSNode *firstchild, *nextsibling; // 第一个孩子和右兄弟指针
}CSNode,*CSTree;
