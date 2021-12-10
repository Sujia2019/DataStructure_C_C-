#include<stdio.h>

#define MaxSize 10
typedef struct{
    char data[MaxSize]; //静态数组存放栈中元素
    int top;  // 栈顶指针
}SqStack;

void InitStack(SqStack &S){
    S.top = -1;
}

// 新元素入栈
bool Push(SqStack &S,char x){
    if(S.top==MaxSize-1){
        return false; // 栈满 报错
    }   
    S.top = S.top+1; // 指针先加1
    S.data[S.top]=x; // 新元素入栈    //等价于 S.data[++S.top] = x;
    return true;
}

bool StackEmpty(SqStack S){
    if(S.top==-1) // 栈空
        return true;
    else 
        return false;
}

// 出栈操作
bool Pop(SqStack &S,char &x){
    if(S.top==-1) // 栈空报错
        return false;
    x = S.data[S.top]; // 栈顶元素先出栈
    S.top = S.top-1;   // 指针再减1   --- 等价于 x=S.data[S.top--]
    return true;
}

bool cracketCheck(char str[], int length){
    SqStack S;
    InitStack(S); // 初始化栈
    for (int i=0;i<length; i++){
        if(str[i]=='('||str[i]=='['||str[i]=='{'){
            Push(S, str[i]);  // 扫描到左括号，入栈
        }else{
            if(StackEmpty(S)) // 扫描到右括号，且当前栈空
                return false; // 匹配失败
            char topElem;
            Pop(S, topElem);   // 栈顶元素出栈
            if(str[i]==')' && topElem!='(')
                return false;
            if(str[i]==']' && topElem!='[')
                return false;
            if(str[i]=='}' && topElem!='{')
                return false;
        }
    }
    return StackEmpty(S);
}