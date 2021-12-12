#include <stdio.h>
#include <stdlib.h>
typedef struct{
    int data;
}ElemType;

typedef struct LinkNode{ // 链式队列结点
    ElemType data;
    struct LinkNode *next;
}LinkNode;
typedef struct{             // 链式队列
    LinkNode *front, *rear; // 队列的队头和队尾指针
}LinkQueue;

// 初始化队列（带头结点）
void InitQueue(LinkQueue &Q){
    // 初识时 front和rear都指向头结点
    Q.front = Q.rear = (LinkNode *)malloc(sizeof(LinkNode));
    Q.front->next=NULL;
}

// 初始化队列（不带头结点）
void InitQueue0(LinkQueue &Q){
    Q.front = NULL;
    Q.rear = NULL;
}

bool IsEmpty0(LinkQueue Q){
    if(Q.front == NULL){
        return true;
    }else{
        return false;
    }
}
// 新元素入队（带头结点）
void EnQueue(LinkQueue &Q, ElemType x){
    LinkNode *s=(LinkNode *)malloc(sizeof(LinkNode));
    s->data=x;
    s->next=NULL;
    Q.rear->next=s; // 新结点插入到rear之后
    Q.rear=s;       // 修改表尾指针
}

// 出队列，带头结点
bool DeQueue(LinkQueue &Q,ElemType &x){
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

void testLinkQueue(){
    LinkQueue Q; // 声明一个队列
    InitQueue(Q);// 初始化队列
}

bool IsEmpty(LinkQueue Q){
    if(Q.front==Q.rear){
        return true;
    }else{
        return false;
    }
}