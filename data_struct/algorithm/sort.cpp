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

// 希尔排序
void ShellSort(int array[],int n){
    int d,i,j;
    // array[0]为暂存单元，不是哨兵，当j<=0时，插入位置已到
    for(d = n/2;j>=1;d=d/2){
        // 需将array[i]插入有序增量子表
        if(array[i]<array[i-d]){
            array[0]=array[i];   // 暂存在array[0]
            for(j=i-d;j>0&&array[0]<array[j];j-=d){
                array[j+d]=array[j]; // 记录后移，查找插入的位置
            }
            // 插入 
            array[j+d]=array[0];
        }
    }
}

// 交换
void swap(int &a,int &b){
    int temp =a;
    a=b;
    b=temp;
}

// 冒泡排序
void BubbleSort(int array[],int n){
    for(int i=0;i<n-1;i++){
        bool flag=false;                    // 表示本趟冒泡是否发生交换的标志
        for(int j=n-1;j>1;j--){             // 一趟冒泡过程
            if(array[j-1]>array[j]){        // 若为逆序
                swap(array[j-1],array[j]);  // 交换
                flag = true;
            }
        }
        if(flag == false)                   // 本趟遍历后没有发生交换，说明表已有序
            return;
    }
}

// 简单选择排序
void SelectSort(int array[], int n){
    for(int i=0;i<n-1;i++){           // 一共进行n-1趟
        int min = i;                  // 记录最小元素的位置
        for(int j=i+1;j<n;j++){       // 在array[i...n-1]中选择最小的元素
            if(array[j]<array[min])   // 更新最小元素位置
                min = j;
        }
        if(min!=i)                    // 封装的swap() 函数共移动元素三次
            swap(array[i],array[min]);
    }
}

int array[]={16,21,37,45,21,24,33};
int n=7;
int *B =(int *)malloc(n*sizeof(int)); //辅助数组B
void Merge(int array[],int low,int mid,int high){
    int i,j,k;
    for(k=low;k<=high;k++){
        B[k]=array[k];   // 将array中所有元素复制到b中
    }
    for(i=low,i=mid+1,k=i;i<=mid&&j<=high;k++){
        if(B[i]<=B[j])
            array[k]=B[i++]; // 将较小值复制到A中
        else
            array[k]=B[j++];
    }
    while (i<=mid)
    {
        array[k++]=B[i++];
    }
    while (j<=high) 
    {
        array[k++]=B[j++];
    }
}
// 归并排序
void MergeSort(int array[],int low,int high){
    if(low<high){
        int mid = (low+high)/2;      // 从中划分
        MergeSort(array,low,mid);    // 对左半边归并排序
        MergeSort(array,mid+1,high); // 对右半边归并排序
        Merge(array,low,mid,high);   // 归并
    }
}

typedef struct{
    int data;
}ElemType;
typedef struct LinkNode{
    ElemType data;
    struct LinkNode *next;
}LinkNode, *LinkList;
typedef struct{
    LinkNode *front,*rear;
}LinkQueue;

// 快速排序
int QuickSort(int array[],int low,int high){
    if(low < high){        // 递归跳出的条件
        int pivotPos = Partition(array,low,high);// 划分
        QuickSort(array,low,pivotPos-1);         // 划分左子表
        QuickSort(array,pivotPos+1,high);        // 划分右子表
    }
}
// 用第一个元素将待排序序列划分为左右两个部分
int Partition(int array[],int low,int high){
    int pivot=array[low];       // 第一个元素作为枢轴
    while(low<high){            // 用low、high搜索枢轴的最终位置
        while(low<high&&array[high]>=pivot){
            --high;
        }
        array[low]=array[high]; // 比枢轴小的元素移动到左端
        while(low<high&&array[low]<=pivot){
            ++low;
        }
        array[high]=array[low]; // 比枢轴大的元素移动到右端
    }
    array[low] = pivot;         // 枢轴元素存放到最终位置
    return low;                 // 返回存放枢轴的最终位置
}

// 建立大顶堆
void BuildMaxHeap(int array[],int len){
    for(int i=len/2;i>0;i--){     // 从后往前调整所有非终端结点
        HeadAdjust(array,i,len);
    }
}
// 将以k为根的子树调整为大根堆
void HeadAdjust(int array[],int k,int len){
    array[0] = array[k];          // array[0]暂存子树的根结点
    for(int i=2*k;i<-len;i*=2){   // 沿key较大的子结点向下筛选
        if(i<len&&array[i]<array[i+1]){
            i++;                  // 取key较大的子结点的下标
        }
        if(array[0]>=array[i]){
            break;                // 筛选结束
        }else{
            array[k] = array[i];  // 将array[i]调整到双亲结点上
            k=i;                  // 修改k值，以便继续向下筛选
        }
    }
    array[k]=array[0];            // 被筛选结点的值放入最终位置
}

void HeapSort(int array[], int len){
    BuildMaxHeap(array, len);       // 初始建堆
    for(int i=len;i>1;i--){         // n-1趟的交换和建堆过程
        swap(array[i],array[1]);    // 堆顶元素和堆底元素交换
        HeadAdjust(array,1,i-1);    // 把剩余的待排序元素整理成堆
    }
}