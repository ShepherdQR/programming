//2020012019:10
// 位运算
#include <stdio.h>
int main(){
    int n1 = 15;
    short n2 = -15;
    unsigned short n3 = 0xffe0;
    char c = 15;
    n1 = n1 >> 2;
    n2 >>= 3;
    n3 >>= 4;
    c >>= 3;
    printf("n1 = %d, n2 = %d, n3 = %d, c = %d\n",n1, n2, n3, c);
    printf("n1 = %x, n2 = %x, n3 = %x, c = %x\n",n1, n2, n3, c);
}
// think: 13, -2, 

// out :
//n1 = 3, n2 = -2, n3 = 4094, c = 1
//n1 = 3, n2 = fffffffe, n3 = ffe, c = 1

/*
15 >> 2: 1111->11=3
-15=fff1 >>3  ->fffe = -2
n3 = ffe0 >>4 = 0ffe
c = 0f >>3 = 01
*/