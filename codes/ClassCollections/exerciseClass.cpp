/*** 
 * @Author: Shepherd Qirong
 * @Date: 2020-02-19 23:21:42
 * @Github: https://github.com/ShepherdQR
 * @LastEditors: Shepherd Qirong
 * @LastEditTime: 2020-02-19 23:34:24
 * @Copyright (c) 2019--20xx Shepherd Qirong. All rights reserved.
*/

#include<iostream>
#include<stdio.h>
#include "exerciseClass.h"
using namespace std;

void C1::GetValue() const{
    //value = 0;// wrong
    //func();// wrong
    cout << "C1::GetValue() is called" << endl;
}