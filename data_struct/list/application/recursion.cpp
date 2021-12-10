#include<stdio.h>

// 计算正整数 n！
int factorial(int n){
    if(n==0||n==1){
       return 1;
    }else{
        return n*factorial(n-1);
    }
}

// 斐波那契
int Fib(int n){
    if(n==0){
        return 0;
    }else if(n==1){
        return 1;
    }else {
        return Fib(n-1)+Fib(n-2);
    }
}

int main(){
    int x = factorial(10);
    printf("10的阶乘为 %d",x);
}