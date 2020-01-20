#include <iostream>
using namespace std;

void swap(int a, int b){
    int temp;
    temp = a; a = b; b = temp;
}

void swap_real(int *aa, int *bb){
    int temp;
    temp = *aa; *aa = *bb; *bb = temp;
}

void swap_realcpp(int &a, int &b){
    int temp;
    temp = a; a = b; b = temp;
}


int jj = 6;
// 引用作为函数的返回值
// 可以把函数的调用写在等号左边
int & setvalue(){return jj;}

int
main(int argc, char * argv[]){
    int a = 1;
    int &b = a;
    b = 2;
    cout << a << b << endl;
    a = 3;
    cout << a << b << endl;

    int &c = b;
    c = 4;
    cout << a << b << c << endl;

    const int &d = a;
    d = 4;// ?编译不报错
    cout << a << d << endl;

    int m = 10, n = 20;
    swap(m, n);
    // m,n是实参，swap函数中的ab是形参
    cout << m << n << endl;

    m = 10; n = 20;
    swap_real(&m, &n);
    // swap_real函数能把m和n的地址交换，值交换。
    cout << m << n << endl;

    m = 10; n = 20;
    swap_realcpp(m, n);
    // swap_realcpp函数能把m和n的地址交换，值交换。
    cout << m << n << endl;

    
    setvalue()=40;//对函数返回的结果进行赋值
    cout << jj << endl;


    return(0);
}