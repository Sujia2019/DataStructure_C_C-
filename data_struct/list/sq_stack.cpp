#include<stdio.h>

#define MaxSize 10
typedef struct{
    int data;
}ElemType;

typedef struct{
    ElemType data[MaxSize]; //静态数组存放栈中元素
    int top;  // 栈顶指针
}SqStack;

void InitStack(SqStack &S){
    S.top = -1;
}

bool StackEmpty(SqStack S){
    if(S.top==-1) // 栈空
        return true;
    else 
        return false;
}

// 新元素入栈
bool Push(SqStack &S,ElemType x){
    if(S.top==MaxSize-1){
        return false; // 栈满 报错
    }   
    S.top = S.top+1; // 指针先加1
    S.data[S.top]=x; // 新元素入栈    //等价于 S.data[++S.top] = x;
    return true;
}

// 出栈操作
bool Pop(SqStack &S,ElemType &x){
    if(S.top==-1) // 栈空报错
        return false;
    x = S.data[S.top]; // 栈顶元素先出栈
    S.top = S.top-1;   // 指针再减1   --- 等价于 x=S.data[S.top--]
    return true;
}

bool GetTop(SqStack &S,ElemType &x){
    if(S.top==-1){
        return false;
    }
    x=S.data[S.top];
    return true;
}