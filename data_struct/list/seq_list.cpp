// 顺序表的实现
#include <stdio.h>
#include <stdlib.h>

#define InitSize 10 //默认的最大长度
typedef struct {
    int *data; //指示动态分配数组的指针
    int MaxSize;  // 顺序表的最大容量
    int length;   // 顺序表的当前长度
}SeqList;

void InitList (SeqList &L) {
    // 用malloc函数申请一片连续的空间
    L.data = (int*)malloc(InitSize*sizeof(int));
    L.length = 0;
    L.MaxSize = InitSize;
}

void IncreaseSize(SeqList &L, int len) {
    int *p=L.data;
    L.data=(int*)malloc((L.MaxSize+len)*sizeof(int));
    for(int i=0;i<L.length;i++){
        L.data[i]=p[i];
    }
    L.MaxSize=L.MaxSize+len;
    free(p);
}

bool ListInsert(SeqList &L,int i,int e){
    if(i<1||i>L.length+1)
        return false;
    if(L.length>=L.MaxSize)
        return false;
    for(int j=L.length;j>=i;j--){
        L.data[j]=L.data[j-1];
    }
    L.data[i-1]=e;
    L.length++;
    return true;
}

bool ListDelete(SeqList &L,int i,int &e){
    if(i<1||i>L.length)
        return false;
    e=L.data[i-1];
    for(int j=i;j<L.length;j++){
        L.data[j-1]=L.data[j];
    }
    L.length--;
    return true;
}

// 按位查找
int GetElem(SeqList L, int i){
    return L.data[i-1];
}

// 按值查找                ElemType
int LocateElem(SeqList L, int e){
    for(int i=0;i<L.length;i++){
        if(L.data[i]==e){
            return i+1;
        }
    }
    // 退出循环说明查找失败
    return -1;
} 


int main(){
    SeqList L;
    int xx = 31;
    InitList(L);
    ListInsert(L,0,33);
    ListInsert(L,1,xx);
    ListInsert(L,2,37);
    ListInsert(L,3,0);
    ListInsert(L,4,1);
    IncreaseSize(L,5);
    printf("Length = %d\n",L.length);
    printf("MaxSize = %d\n",L.MaxSize);
    ListInsert(L,5,7);
    ListDelete(L, 1, xx);
    printf("第%d个位置的值为 = %d\n",1,GetElem(L,1));
    return 0;
}