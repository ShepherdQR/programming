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

Complex::Complex(double r_in, double i_in):real(r_in),imagination(i_in){
    std::cout << "Complex: Normal Default Constructor called, and the number is: ( " << real << ", " << imagination << " )." << std::endl;
}

Complex Complex::AddOne(){
    this-> real +=1;
    this-> complexPrint();
    return *this;
}