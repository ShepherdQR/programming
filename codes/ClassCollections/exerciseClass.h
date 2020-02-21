/*** 
 * @Author: Shepherd Qirong
 * @Date: 2020-02-19 23:23:57
 * @Github: https://github.com/ShepherdQR
 * @LastEditors: Shepherd Qirong
 * @LastEditTime: 2020-02-19 23:56:21
 * @Copyright (c) 2019--20xx Shepherd Qirong. All rights reserved.
*/

#ifndef EXERCISE_CLASS_H
#define EXERCISE_CLASS_H


class C1{
    private:
        int value_inner;
    public:
        int value = 3;
        C1(){ value_inner = 1;};
        void GetValue() const;
        void func(){};

        int GetValue_p()const {return value_inner*2;};
        int GetValue_p() {return value_inner*4;};
        
};

#endif