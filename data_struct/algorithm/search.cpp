#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int data;
}ElemType;

typedef struct{
    int *elem;
    int len;
}SSTable;

// 折半查找
int Binary_Search(SSTable L, int key){
    int low = 0,high=L.len-1,mid;
    while (low<=high)
    {
        mid = (low+high)/2;
        if(L.elem[mid] ==key)
            return mid;
        else if(L.elem[mid]>key)
            high=mid-1;
        else
            low=mid+1;
        
    }
    return -1;
    
}