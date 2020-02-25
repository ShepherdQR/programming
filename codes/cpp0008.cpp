/* ===========
//  * Author: Shepherd Qirong
//  * Date: 2020-02-19 15:11:21
//  * Github: https://github.com/ShepherdQR
//  * LastEditors: Shepherd Qirong
//  * LastEditTime: 2020-02-23 21:11:59
//  * Copyright (c) 2019--20xx Shepherd Qirong. All rights reserved.
*/
/*** 
 * @Author: Shepherd Qirong
 * @Date: 2020-02-19 15:11:21
 * @Github: https://github.com/ShepherdQR
 * @LastEditors: Shepherd Qirong
 * @LastEditTime: 2020-02-19 23:59:23
 * @Copyright (c) 2019--20xx Shepherd Qirong. All rights reserved.
*/


// 重载


#include<iostream>
#include<stdio.h>
using namespace std;
#include"complex.h"
#include "exerciseClass.h"



int main(){

    CStudent student;
    student.nAge = 5;
    cout << student << "hi";




    cout << "hi" << endl;

    Complex p(2,3 ), q(2,3), c, d;
    c = p + q;
    c = p - q;
    d = p.operator+(p);
    d = p.operator-(p);

    String s1;
    s1 = "Hello.";
    cout << s1.c_str() << endl;
    s1 = "world.";
    cout << s1.c_str() << endl;



    //=====================
    CArray a;
    for (size_t i=0; i < 5; ++i){
        a.push_back(i);
    }
    CArray a2, a3;
    a2 = a;

    for (size_t i=0; i < a.length(); ++i){
        cout << a2[i] << ", ";
    }

    a2 = a3;
    for (size_t i=0; i < a2.length(); ++i){
        cout << a2[i] << ", ";
    }
    cout << "a2 ok......" << endl;

    a[3] = 100;
    CArray a4(a);
    for (size_t i=0; i < a4.length(); ++i){
        cout << a4[i] << ", ";
    }


    
    



    return 0;
}