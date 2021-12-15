#include <stdio.h>
#include <stdlib.h>

// 二叉排序树结点
typedef struct BSTNode{
    int key;
    struct BSTNode *lchild,*rchild;
}BSTNode,*BSTree;

//在二叉排序树中查找值为key的结点 最坏空间复杂度O(1)
BSTNode *BST_Search(BSTree T,int key){
    while (T!=NULL&&key!=T->key){
        if(key<T->key){  // 若树空或等于根结点的值，则结束循环
            T = T->lchild;
        }else{
            T = T->rchild;
        }
    }
}

// 在二叉排序树中查找值为key的结点（递归实现）
BSTNode *BSTSearch(BSTree T,int key){  // 最坏空间复杂度O(h) 树的高度
    if(T == NULL){
        return NULL; // 查找失败
    }
    if(key == T->key){
        return T;    // 查找成功
    }else if (key < T->key){
        return BSTSearch(T->lchild, key); // 在左子树中找
    }else{
        return BSTSearch(T->rchild, key); // 在右子树中找
    }
}

// 在二叉排序树中插入关键字为k的新结点(递归实现) 最坏空间复杂度O(h) (因为是递归呗，递归调用多少层就费多少空间)
int BST_Insert(BSTree &T, int k){
    if(T == NULL){
        T = (BSTree)malloc(sizeof(BSTNode));
        T->key = k;
        T->lchild = T->rchild = NULL;
        return 1; // 返回1 - 插入成功
    }
    else if(k == T->key){ // 树中存在相同关键字的结点，插入失败
        return 0;
    }
    else if(k < T->key){ // 插入到T的左子树
        return BST_Insert(T->lchild, k);
    }
    else{ // 插入到T的右子树
        return BST_Insert(T->rchild,k);
    }
}

int str[] = {50,66,60,26,21,30,70,68};
// 按照str[] 中的关键字序列建立二叉排序树
void Create_BST(BSTree &T,int str[],int n){
    T = NULL;
    int i=0;
    while (i<n) // 依次将每个关键字插入到二叉排序树中
    {
        BST_Insert(T,str[i]);
        i++;
    }
    
}