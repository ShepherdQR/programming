/* ===========
//  * Author: Shepherd Qirong
//  * Date: 2020-02-19 15:26:15
//  * Github: https://github.com/ShepherdQR
//  * LastEditors: Shepherd Qirong
//  * LastEditTime: 2020-02-29 13:52:20
//  * Copyright (c) 2019--20xx Shepherd Qirong. All rights reserved.
*/

#ifndef COMPLEX_H
#define COMPLEX_H

class Complex{
    private:
        double real, imagination;
    public:
        void complexPrint();
        //double real, imagination;
        Complex(double , double  );
        Complex(){real = 0; imagination = 0;}
        //Complex(const Complex & , const Complex & );
        Complex AddOne();
    
        Complex operator+ (const Complex &);
        Complex operator- (const Complex &);
        Complex operator+ (double r);  
        //friend Complex operator+ (double r, const Complex & c);  
        
};

#endif