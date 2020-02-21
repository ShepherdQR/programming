/*** 
 * @Author: Shepherd Qirong
 * @Date: 2020-02-19 15:26:15
 * @Github: https://github.com/ShepherdQR
 * @LastEditors: Shepherd Qirong
 * @LastEditTime: 2020-02-19 22:21:22
 * @Copyright (c) 2019--20xx Shepherd Qirong. All rights reserved.
*/
#ifndef COMPLEX_H
#define COMPLEX_H

class Complex{
    private:
        double real, imagination;
    public:
        void complexPrint();
        Complex(double r_in, double i_in);
        Complex AddOne();
};

#endif