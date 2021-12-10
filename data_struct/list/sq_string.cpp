#include<stdio.h>
#include <stdlib.h>

#define MAXLEN 255
typedef struct{
    char ch[MAXLEN];
    int length;
}SString; // 静态数组实现 - 定长顺序数组

typedef struct{
    char *ch;          // 按串长分配存储区，ch指向串的基地址
    int length;        // 串的长度
}HString; // 动态数组实现 - 堆分配存储

void main(){
    HString S;
    S.ch = (char *) malloc(MAXLEN * sizeof(char));
    S.length = 0;
}

// 求子串
bool SubString(SString &Sub,SString S, int pos,int len){
    // 子串范围越界
    if(pos+len-1>S.length){
        return false;
    }
    for(int i=pos;i<pos+len;i++){
        Sub.ch[i-pos+1] = S.ch[i];
    }
    Sub.length=len;
    return true;
}

// 比较操作 若S>T ，则返回值>0;若 S=T, 则返回值=0；若S<T,则返回值 <0
int StrCompare(SString S,SString T){
    for(int i=1;i<=S.length && i<=T.length;i++){
        if(S.ch[i]!=T.ch[i]){
            return S.ch[i]-T.ch[i];
        }
    }
    return S.length - T.length;
}

int StrLength(SString S){
    return S.length;
}

int Index(SString S, SString T){
    int i=1, n=StrLength(S),m=StrLength(T);
    SString sub; // 用于暂存子串
    while(i<=n-m+1){
        SubString(sub,S,i,m);
        if(StrCompare(sub,T)!=0){
            ++i;
        }else{
            return i; // 返回子串在主串中的位置
        }
    }
    return 0; // S中不存在与T相等的子串
}

// 朴素模式匹配 时间复杂度O(n) ;
// 如果S = aaaaaab,  T = aaaab，时间复杂度为O(nm) 两者长度的乘积
int IndexString(SString S,SString T){
    int i=1,j=1;
    while(i<=S.length && j<= T.length){
        if(S.ch[i]==T.ch[j]){
            ++i; ++j;
        }else{
            i=i-j+2;
            j=1;
        }
    }
    if(j>T.length){
        return i-T.length; // 返回位置
    }else{
        return 0;
    }
}

// KMP 算法
int Index_KMP(SString S,SString T){
    int i=1;
    int j=1;
    int next[T.length+1];
    get_next(T,next);
    int tn = T.length;
    while(i < S.length && i-T.length >= 0){
        if(S.ch[i] == T.ch[j]){
            ++i;
            ++j;
        }else {
            j=next[j];
        }
    }
    if(j>T.length){
        return i-T.length;
    }else{
        return 0;
    }
}

// 求模式串T的next数组
void get_next(SString T,int next[]){
    int i=1,j=0;
    next[1]=0;
    while(i<T.length){
        if(j==0||T.ch[i]==T.ch[j]){
            ++i; ++j;
            // 若pi=pj，则next[j+1] = next[j]+1
            next[i]=j;
        }else{
            j=next[j];
        }
    }
}