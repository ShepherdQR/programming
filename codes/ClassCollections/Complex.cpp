/* ===========
//  * Author: Shepherd Qirong
//  * Date: 2020-02-19 15:55:14
//  * Github: https://github.com/ShepherdQR
//  * LastEditors: Shepherd Qirong
//  * LastEditTime: 2020-08-23 22:43:34
//  * Copyright (c) 2019--20xx Shepherd Qirong. All rights reserved.
*/


#include<iostream>
#include "Complex.h"
using namespace std;

/*********************** 20200823215459 *******
 *@Brief:	Default COnstructor and Destructor.
 *@Param:	Null.
 *@Return:	NULL.
 */
Complex::Complex(){
    _real = _imagination = 0;
    cout << "Default Constructor" << *this << endl;
}

Complex::~Complex(){
    cout << "Destructor: " << *this << endl;
}

Complex::Complex(const double realIn, const double imaginationIn):_imagination(realIn),_real(imaginationIn){
    cout << "2 Parameters Constructor" << *this << endl;
}
Complex::Complex(const double realIn){
    _real = realIn;
    _imagination = 0;
    cout << "1 Parameters Constructor" << *this << endl;
}

/*********************** 20200823222137 *******
 *@Brief:	Operator +.
 *@Param:	.
 *@Return:	NULL.
 */
Complex Complex::operator+ (const Complex & com2){
    return Complex(_real + com2._real, _imagination + com2._imagination);
}
Complex Complex::operator+ (double r){
    return Complex(_real + r, _imagination);
}

Complex operator+ (const Complex & com1, const Complex & com2){
    return Complex(com1._real + com2._real, com1._imagination + com2._imagination);
}
Complex operator+ (double r, const Complex & c){
    return Complex(c._real + r, c._imagination);
}

Complex Complex::realAdd(const double realIn){
    this-> _real += realIn;
    this-> display();
    return *this;
}


/*********************** 20200823222137 *******
 *@Brief:	Operator -.
 *@Param:	.
 *@Return:	NULL.
 */
Complex Complex::operator- (const Complex & com2){
    return Complex(_real - com2._real, _imagination - com2._imagination);
}





/*********************** 20200823221723 *******
 *@Brief:	Show complex.
 *@Param:	NULL.
 *@Return:	NULL.
 */
std::ostream& operator<< (std::ostream& os, const Complex& complexIn){
    os << '(' << complexIn._real << ", " << complexIn._imagination << ')';
    return os;
}

void Complex::display(){
    cout << '(' << _real << ", " << _imagination << ')';
}
