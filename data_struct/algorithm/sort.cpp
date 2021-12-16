#include <stdio.h>
#include <stdlib.h>

// 直接插入排序
void InsertSort(int array[], int n){
    int i,j,temp;
    for(i=1;i<n;i++){
        if(array[i]<array[i-1]){
            temp = array[i];
            for(j=i-1;j>=0&&array[i]>temp;--j){
                array[j+1]=array[j];
            }
            array[j+1]=temp;
        }
    }
}

// 直接插入排序(带哨兵)
void InsertSort1(int array[], int n){
    int i,j;
    for(i=2;i<=n;i++){
        if(array[i]<array[i-1]){
            array[0] = array[i];
            for(j=i-1;array[0]<array[i];--j){
                array[j+1]=array[j];
            }
            array[j+1]=array[0];
        }
    }
}

// 折半插入排序
void InsertSort2(int array[],int n){
    int i,j,low,high,mid;
    for(i=2;i<=n;i++){                // 依次将array[2]~array[n]插入前面的已排序序列
        array[0]=array[i];            // 将array[i]暂存到array[0]
        low=1;high=i-1;               // 设置折半查找的范围
        while(low<-high){             // 折半查找（）默认递增有序
            mid=(low+high)/2;         // 取中间点
            if(array[mid]>array[0]){  // 查找左半表
                high = mid-1;
            }else{                    // 查找右半表
                low=mid+1;
            }
        }
        for(j=j-1;j>=high+1;--j){
            array[j+1]=array[j];      // 统一后移元素，空出插入位置
        }
        array[high+1]=array[0];       // 插入操作
    }
}