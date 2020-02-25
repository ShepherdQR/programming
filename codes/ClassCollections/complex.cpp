
/*** 
 * @Author: Shepherd Qirong
 * @Date: 2020-02-19 15:55:14
 * @Github: https://github.com/ShepherdQR
 * @LastEditors: Shepherd Qirong
 * @LastEditTime: 2020-02-19 22:22:24
 * @Copyright (c) 2019--20xx Shepherd Qirong. All rights reserved.
*/

#include<iostream>
#include<stdio.h>
#include "complex.h"

void Complex::complexPrint(){
    std::cout << "( " << real << ", " << imagination << " )" << std::endl;

}

Complex::Complex(double  r_in  , double i_in = 0.0 ):real(r_in),imagination(i_in){
    std::cout << "Complex: Normal Default Constructor called, and the number is: ( " << real << ", " << imagination << " )." << std::endl;
}

Complex Complex::AddOne(){
    this-> real +=1;
    this-> complexPrint();
    return *this;
}

// wrong  ????
/*
Complex Complex::operator+ (const Complex & com1, const Complex & com2){
    return Complex(com1.real + com2.real, com1.imagination + com2.imagination);
}
*/

Complex Complex::operator+ (const Complex & com2){
    return Complex(real + com2.real, imagination + com2.imagination);
}

Complex Complex::operator- (const Complex & com2){
    return Complex(real - com2.real, imagination - com2.imagination);
}

Complex Complex::operator+ (double r){
    //可以实现 c+5；
    //但是计算 5+c需要 r 和 c两个参数。
    return Complex(real + r, imagination);
}
/*
Complex Complex::operator+ (double r, const Complex & c){
    //error ???
    //error: ‘Complex Complex::operator+(double, const Complex&)’ must take either zero or one argument
    //可以实现 5+c
    return Complex(c.real + r, c.imagination);
}
*/

