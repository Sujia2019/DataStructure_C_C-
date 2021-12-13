#include <stdio.h>
#include <stdlib.h>
#define MaxSize 100
typedef struct{
    int data;
}ElemType;
struct TreeNode{
    ElemType value; 
    bool isEmpty;
};
// 定义一个长度为MaxSize的数组t 按照从上至下，从左至右的顺序依次存储完全二叉树中的各个结点
TreeNode t[MaxSize];
