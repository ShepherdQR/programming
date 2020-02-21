// t001 c++
// 注意需要cout、/n 才会显示输出。
#include<iostream>
#include<stdio.h>
using namespace std;

void PrintMin(int a, int b){
    if(a<b)
        cout << a;
    else
        cout << b;
    cout<< endl;
}
int main(int argc, char** argv){
    void (*pf)(int, int);
    int x=4, y=5;
    pf = PrintMin;
    pf(x,y);
    //system("pause");
    cout << "t001_ok" << endl;
    return(0);
}