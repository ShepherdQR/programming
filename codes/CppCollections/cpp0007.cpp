/*** 
 * @Author: Shepherd Qirong
 * @Date: 2020-02-19 15:11:21
 * @Github: https://github.com/ShepherdQR
 * @LastEditors: Shepherd Qirong
 * @LastEditTime: 2020-02-19 23:59:23
 * @Copyright (c) 2019--20xx Shepherd Qirong. All rights reserved.
*/


// time 2020021915:11
// class 04

// this
// const

#include<iostream>
#include<stdio.h>
using namespace std;
#include"complex.h"
#include"exerciseClass.h"

class A{
    int i;
    public:
        void Hello(){
            //没有调用成员对象，用的时候用空指针调用Hello函数是可以的
            cout << "hi" << endl;
        }//in c: void Hello(A *this){cout << i << "hi" << endl;}

        // wrong, 空指针导致this->i错误，程序崩溃
        //void Hello(){cout << i << "hi" << endl;}//in c: void Hello(A *this){cout << this->i << "hi" << endl;}
};

void PrintfC1(const C1 & object1){
    cout << object1.value << endl;
}

int main(){
    cout << "hi" << endl;

    // e01
    Complex e1(1,1), e2(0,0);
    e2 = e1.AddOne();
    const Complex e3();

    // e02
    A *p = NULL;
    p-> Hello();// in c: Hello(p);

    //e03
    const C1 e4;
    //e4.value = 100;//error: assignment of member ‘C1::value’ in read-only object
    //e4.func();//error: passing ‘const C1’ as ‘this’ argument discards qualifiers [-fpermissive]
    e4.GetValue();

    // const func and un-const func with the same name and parameters:
    C1 e5;
    cout << e4.GetValue_p() << " , " << e5.GetValue_p() << endl;
    
    // const xx &:
    int x1 = 1;
    const int &x2 = x1;
    //x2 = 5;//error:assignment of read-only reference ‘x2’
    x1 = 5;

    PrintfC1(e5);


    return 0;
}