#include <stdlib.h>
#include <stdio.h>

typedef struct LNode{   // 定义单链表结点类型
    int data;           // 每个结点存放一个数据元素
    struct LNode *next; // 指针指向下一个节点
}LNode, *LinkList;

// 初始化一个空的不带头节点的单链表
bool InitList(LinkList &L){
    L = NULL;   // 空表，暂时没有任何节点 防止脏数据
    return true;
}
// 判断单链表是否为空
bool Empty(LinkList L){
    return (L==NULL);
}


// 初始化一个带头节点的单链表
bool InitList2(LinkList &L){
    L = (LNode *)malloc(sizeof(LNode)); // 分配一个头节点
    if(L==NULL)                         // 内存不足，分配失败
        return false;
    L->next = NULL;                     // 头节点之后暂时还没有节点
    return true;
}
bool Empty2(LinkList L){
    if(L->next==NULL){
        return true;
    }else{
        return false;
    }
}

// 在第i个位置插入元素e 带头节点
bool ListInsert(LinkList &L,int i,int e){
    if(i<1){
        return false;
    }
    LNode *p; // 指针p指向当前扫描到的节点
    int j=0;  // 当前p指向的是第几个节点
    p=L;      // L指向头节点，头节点是第0个节点（不存数据）
    while(p!=NULL&&j<i-1){// 循环找到第i-1个节点
        p=p->next;
        j++;
    }
    if(p==NULL) { // i值不合法
        return false;
    }
    LNode *s = (LNode *)malloc(sizeof(LNode));
    s->data = e;
    s->next = p->next;
    p->next = s;   //将节点s连到p之后
    return true;
}

// 指定节点后插操作
bool InsertNextNode(LNode *p,int e){
    if(p==NULL){
        return false;
    }
    LNode *s =(LNode *)malloc(sizeof(LNode));
    if(s==NULL){ // 内存分配失败
        return false;
    }
    s->data = e; //用节点s保存数据元素e
    s->next = p->next;
    p->next=s;   //将节点s连到p之后
    return true;
}

// 指定结点的前插操作: 在p结点之前插入结点s   O(1)
bool InsertPriorNode(LNode *p,LNode *s){
    if(p==NULL||s==NULL){
        return false;
    }
    s->next = p->next; 
    p->next = s;           // 将s连到p之后
    int temp = p->data;    // 交换s和p的数据部分
    p->data = s->data;
    s->data = temp;
    return true;
}

// 按位序删除  O(n)
bool ListDelete(LinkList &L,int i,int &e){
    if(i<1){
        return false;
    }
    LNode *p; //指针p指向当前扫描到的结点
    int j=0;  //当前p指向的是第几个结点
    p=L;      //L指向头结点，头结点是第0个结点（不存数据）
    while(p!=NULL&&j<i-1){ //循环找到第i-1个结点
        p=p->next;
        j++;
    }
    if(p==NULL){  // i 值不合法
        return false;
    }
    if(p->next==NULL){  // 第i-1个结点之后已无其他结点 
        return false;
    }
    LNode *q = p->next; // 令q指向被删除结点
    e=q->data;          // 用e返回元素的值
    p->next=q->next;    // 将*q结点从链中“断开”
    free(q);            // 释放结点的存储空间
    return true;        // 删除成功
}

// 删除指定结点P
bool DeleteNode(LNode *p){
    if(p==NULL){
        return false;
    }
    LNode *q = p->next;     // 令q指向*p的后继结点
    p->data=p->next->data;  // 和后继结点交换数据域
    p->next=q->next;        // 将*q结点从链中断开
    free(q);                // 释放后继结点的存储空间
}

// 带头结点 按位查找  O(n)
LNode * GetElem(LinkList L, int i){
    if(i<0){
        return NULL;
    }
    LNode *p;   // 指针p指向当前扫描到的结点
    int j=0;    // 当前p指向的是第几个结点
    p = L;      // L指向头结点，头结点是第0个结点 不存数据
    while(p!=NULL && j<i){  // 循环找到第i个结点
        p = p->next;
        j++;
    }
    return p;
}

// 按值查找  找到数据域==e的结点
LNode * LocateElem(LinkList L,int e){
    LNode *p = L->next;
    // 从第1个结点开始查找数据域为e的结点
    while(p!=NULL && p->data!=e){
        p=p->next;
    }
    return p;    // 找到后返回该结点指针，否则返回NULL 
}

// 求表的长度
int Length(LinkList L){
    int len = 0;
    LNode *p = L;
    while(p->next!=NULL){
        p=p->next;
        len++;
    }
    return len;
}

// 尾插法建立单链表 O(n)
LinkList List_TailInsert(LinkList &L){
    int x;
    L=(LinkList)malloc(sizeof(LNode)); // 建立头结点
    LNode *s, *r=L;                    // r为表尾指针
    scanf("%d", &x);                   // 用户输入结点的值
    while(x!=9999){                    // 当用户输入9999时认为结束
        s=(LNode *)malloc(sizeof(LNode));
        s->data=x;
        r->next=s;                     // r的下一个结点是s，那么此时s是表尾结点
        r=s;                           // r指向新的表尾结点
        scanf("%d",&x);
    }
    r->next=NULL;                      // 尾结点指针置空
    return L;
}

// 头插法建立单链表 - 相当于每次都对头结点做一次后插操作
// 可用于链表逆制
LinkList List_HeadInsert(LinkList &L){
    LNode *s;
    int x;
    L=(LinkList)malloc(sizeof(LNode));    // 创建头结点
    L->next=NULL;                         // 初始为空链表
    scanf("%d",&x);                       // 输入结点的值
    while(x!=9999){
        s=(LNode *)malloc(sizeof(LNode)); // 创建新结点
        s->data = x;
        s->next = L->next;  // 将L后面的结点接到s后面
        L->next=s;          // 将新结点插入表中，L为头指针
        scanf("%d",&x);
    }
    return L;
}

// 循环单链表初始化
bool InitList_XunHuan(LinkList &L){
    L = (LNode *)malloc(sizeof(LNode)); // 分配一个头结点
    if(L==NULL){
        return false;
    }
    L->next = L; //头结点next指向头结点
    return true;
}

// 判断循环单链表是否为空
bool Empty(LinkList L){
    if(L->next == L){
        return true;
    }else{
        return false;
    }
}

// 判断结点p是否为循环单链表的表尾结点
bool isTail(LinkList L, LNode *p){
    if (p->next==L){
        return true;
    }else{
        return false;
    }
} 

void test(){
    LinkList L; // 声明一个指向单链表的指针
    // 初始化空表
    InitList(L);
}