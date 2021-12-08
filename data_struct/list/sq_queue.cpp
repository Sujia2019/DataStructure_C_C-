#include<stdio.h>

typedef struct{
    int data;
}ElemType;

#define MaxSize 10
typedef struct{
    ElemType data[MaxSize];
    int front;  // 队头指针
    int rear;   // 队尾指针
}SqQueue;

// 入队
// bool EnQueue(SqQueue &Q,ElemType x){
//     if()// 队满报错
//         return false;
//     Q.data[Q.rear]=x;          //新元素插入队尾
//     Q.rear=(Q.rear+1)%MaxSize; //队尾指针+1取模
//     return true;
// }

// 循环队列入队
bool EnQueue(SqQueue &Q,ElemType x){
    if((Q.rear+1)%MaxSize == Q.front){
        return false;
    }
    Q.data[Q.rear] = x;
    Q.rear=(Q.rear+1)%MaxSize;
    return true;
}

// 出队
bool DeQueue(SqQueue &Q, ElemType &x){
    if(Q.rear == Q.front){
        return false;
    }
    x=Q.data[Q.front];
    Q.front=(Q.front+1)%MaxSize;
    return true;
}

// 获得队列头元素的值，用x返回
bool GetHead(SqQueue Q,ElemType &x){
    if(Q.rear == Q.front){
        return false;
    }
    x=Q.data[Q.front];
    return true; 
}

