#include <stdio.h>
#include <stdlib.h>
#define MaxSize 100
typedef struct{
    int data;
}ElemType;

typedef struct  BiTNode{
    ElemType data;
    struct BiTNode *lchild;
    struct BiTNode *rchild;
   // struct BiTNode *parent; //父结点指针
}BiTNode,*BiTree;

// 先序遍历
void PreOrder(BiTree T){
    if(T!=NULL){
        visit(T);
        PreOrder(T->lchild);
        PreOrder(T->rchild);
    }
}

// 中序遍历
void InOrder(BiTree T){
    if(T!=NULL){
        InOrder(T->lchild);
        visit(T);
        InOrder(T->rchild);
    }
}

void PostOrder(BiTree T){
    if(T!=NULL){
        PostOrder(T->lchild);
        PostOrder(T->rchild);
        visit(T);
    }
}

void visit(BiTree T){
    printf("访问结点：%d",T->data.data); 
}

int treeDepth(BiTree T){
    if(T == NULL){
        return 0;
    }
    else{
        int l = treeDepth(T->lchild);
        int r = treeDepth(T->rchild);
        // 树的深度 = Max(左子树深度，右子树深度) +1
        return l > r?l+1:r+1;
    }
}
typedef struct LinkNode{ // 链式队列结点
    BiTNode * data; //  存指针而不是结点
    struct LinkNode *next;
}LinkNode;

typedef struct{
    LinkNode *front,*rear;
}LinkQueue;

// 新元素入队（带头结点）
void EnQueue(LinkQueue &Q, BiTNode * x){
    LinkNode *s=(LinkNode *)malloc(sizeof(LinkNode));
    s->data=x;
    s->next=NULL;
    Q.rear->next=s; // 新结点插入到rear之后
    Q.rear=s;       // 修改表尾指针
}

// 初始化队列（带头结点）
void InitQueue(LinkQueue &Q){
    // 初识时 front和rear都指向头结点
    Q.front = Q.rear = (LinkNode *)malloc(sizeof(LinkNode));
    Q.front->next=NULL;
}

bool IsEmpty(LinkQueue Q){
    if(Q.front==Q.rear){
        return true;
    }else{
        return false;
    }
}

// 出队列，带头结点
bool DeQueue(LinkQueue &Q,BiTNode * x){
    if(Q.front==Q.rear){
        return false; // 空队
    }
    LinkNode *p = Q.front->next; 
    x=p->data;              // 用变量x返回队头元素
    Q.front->next=p->next;  // 修改头结点的next指针
    if(Q.rear==p){          // 此次是最后一个结点出队
        Q.rear = Q.front;   // 修改rear指针
    }
    free(p);                // 释放结点空间
    return true;
}

// 层序遍历
void LevelOrder(BiTree T){
    LinkQueue Q;
    InitQueue(Q);
    BiTree p;
    EnQueue(Q,T);
    while (!IsEmpty(Q))
    {
        DeQueue(Q, p);
        visit(p);
        if(p->lchild!=NULL){
            EnQueue(Q,p->lchild);
        }
        if(p->rchild!=NULL){
            EnQueue(Q,p->rchild);
        }
    }
}

// 线索二叉树结点
typedef struct ThreadNode
{
    ElemType data;
    struct  ThreadNode *lchild,*rchild;
    int ltag,rtag; // 左右线索标志
    // tag == 0，表示指针指向孩子
    // tag == 1，表示指针是“线索”
}ThreadNode,*ThreadTree;


// 全局变量 pre 指向当前访问结点的前驱
ThreadNode *pre = NULL;

void visit1(ThreadNode *q){
    if(q->lchild==NULL){// 左子树为空，建立前驱线索
        q->lchild=pre;
        q->ltag=1;
    }
    if(pre!=NULL&&pre->rchild==NULL){
        pre->rchild=q; // 建立前驱结点的后继结点
        pre->rtag=1;
    }
    pre=q;
}
// 中序遍历二叉树，一边遍历一边线索化
void InThread(ThreadTree T){
    if(T!=NULL){
        InThread(T->lchild);
        visit1(T);
        InThread(T->rchild);
    }
}

// 中序线索化二叉树T
void CreateInThread(ThreadTree T){
    pre = NULL;
    if(T!=NULL){
        InThread(T);
        if(pre->rchild==NULL){
            pre->rtag = 1; // 处理遍历的最后一个结点
        }
    }
}

// 先序遍历二叉树，一边遍历一边线索化线索化
void PreThread(ThreadTree T){
    if(T!=NULL){
        visit1(T); // 先处理根结点
        PreThread(T->lchild);
        PreThread(T->rchild); 
    }
}

void CreatePreThread(ThreadTree T){
    pre = NULL;
    if(T!=NULL){
        PreThread(T);
        if(pre->rchild == NULL){
            pre->rtag = 1; // 处理遍历的最后一个结点
        }
    }
}

void PostThread(ThreadTree T){
    if(T!=NULL){
        PostThread(T->lchild);
        PostThread(T->rchild);
        visit1(T);
    }
}

// 后序线索化二叉树T
void CreatePostThread(ThreadTree T){
    pre = NULL;
    if(T!=NULL){
        PostThread(T);
        if(pre->rchild==NULL){
            pre->rtag=1;
        }
    }
}