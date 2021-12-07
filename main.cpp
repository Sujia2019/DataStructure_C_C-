#include <stdio.h>

void test(int &x){
    x = 1024;
    printf("x=%d\n",x);
}

int main()
{
    int x = 1;
    printf("x=%d\n",x);
    test(x);
    printf("x=%d\n",x);
}