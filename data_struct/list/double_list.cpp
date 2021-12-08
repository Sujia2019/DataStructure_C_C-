#include <stdlib.h>
#include <stdio.h>

// 单链表无法逆向检索，有时候不方便
// 双链表：可进可退，存储密度更低一丢丢

typedef struct DNode{          // 定义双链表结点类型
    int data;                  // 数据域
    struct DNode *prior,*next; // 前驱和后驱指针
}DNode, *DLinkList;

// 初始化双链表
bool InitDLinkList(DLinkList &L){
    L = (DNode *)malloc(sizeof(DNode));//分配一个头结点
    if(L==NULL){
        return false;//内存不足 分配失败
    }
    L->prior = NULL;
    L->next = NULL;
    return true;
}

// 判断是否为空
bool Empty(DLinkList L){
    if(L->next == NULL){
        return true;
    }else{
        return false; 
    }
}

//在p结点之后插入s结点
bool InsertNextDNode(DNode *p, DNode *s){
    if(p==NULL || s==NULL){
        return false; // 参数非法
    }
    s->next = p->next;
    if(p->next!=NULL){// 判断p结点是否有后继结点
        p->next->prior = s;    
    }
    s->prior=p;
    p->next=s;
    // 修改指针时一定要注意顺序！！！
}

// 删除指定结点
bool DeleteNextDNode(DNode *p){
    if (p==NULL){
        return false;
    }
    DNode *q = p->next;// 找到p的后继节点
    if(q==NULL){
        return false;  // p没有后继节点
    }
    p->next = q->next;
    if(q->next!=NULL){ //q结点不是最后一个结点
        q->next->prior = p;
    }
    free(q);
    return true; 
}

void DestoryList(DLinkList &L){
    // 循环释放各个数据结点
    while(L->next != NULL){
        DeleteNextDNode(L);
    }
    free(L);// 释放头结点
    L=NULL; // 头指针指向NULL
}


void testDLinkList(){
    // 初始化双链表
}
int main(){

}