// gcc day01.c

/*
// t001 c
// gcc day01.c, /n才会显示
#include<stdio.h>

void PrintMin(int a, int b){
    if(a<b)
        printf("%d",a);
    else
        printf("%d",b);
    printf("\n");
}
int main(int argc, char** argv){
    void (*pf)(int, int);
    int x=4, y=5;
    pf = PrintMin;
    pf(x,y);
    return(0);
}

*/