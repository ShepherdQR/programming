/* ===========
//  * Author: Shepherd Qirong
//  * Date: 2020-02-19 15:26:15
//  * Github: https://github.com/ShepherdQR
//  * LastEditors: Shepherd Qirong
//  * LastEditTime: 2020-08-23 22:35:33
//  * Copyright (c) 2019--20xx Shepherd Qirong. All rights reserved.
*/


#ifndef COMPLEX_H
#define COMPLEX_H

class Complex{
    private:
        double _real;
        double _imagination;

    public:

        /*********************** 20200823215459 *******
         *@Brief:	Default COnstructor and Destructor.
         *@Param:	Null.
         *@Return:	NULL.
         */
        Complex();
        ~Complex();
        Complex(const double realIn, const double);
        Complex(const double realIn);


        /*********************** 20200823222137 *******
         *@Brief:	Operator + .
         *@Param:	.
         *@Return:	NULL.
         */
        Complex operator+ (const Complex &);
        Complex operator+ (double r);

        friend Complex operator+ (const Complex & com1, const Complex & com2);
        friend Complex operator+ (const double r, const Complex & c);
        
        Complex realAdd(const double realIn);


        /*********************** 20200823222948 *******
         *@Brief:	Operator -.
         *@Param:	.
         *@Return:	NULL.
         */
        Complex operator- (const Complex &);
         



        /*********************** 20200823221723 *******
         *@Brief:	Show complex.
         *@Param:	NULL.
         *@Return:	NULL.
         */
        friend std::ostream& operator<< (std::ostream& os, const Complex& complexIn);void display();



 
};

#endif