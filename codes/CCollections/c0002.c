
// unsigned int 数组， 个位数从小到大排列

#include<stdio.h>
#include<stdlib.h>

int MyCompare(const void * elem1, const void * elem2){
    unsigned int * p1, * p2;
    p1 = (unsigned int *) elem1;//
    // * elem1 no legal,因为编译起不知道elem1指向的元素是多少字节，编译器不知道这个东西多大。需要类型转换
    p2 = (unsigned int *) elem2;
    return (*p1 %10)-(*p2 % 10);//return min
}
#define NUM 5
int main(){
    unsigned int an[NUM] ={8, 123, 11, 10, 4};
    qsort(an, NUM, sizeof(unsigned int),MyCompare);
    for (int i = 0; i != NUM; ++i)
        printf("%d\n",an[i]);
    return(0);
}
// correct out: 10 11 123 4 8
