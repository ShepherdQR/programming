/* ===========
//  * Author: Shepherd Qirong
//  * Date: 2020-02-19 23:23:57
//  * Github: https://github.com/ShepherdQR
//  * LastEditors: Shepherd Qirong
//  * LastEditTime: 2020-02-23 21:10:13
//  * Copyright (c) 2019--20xx Shepherd Qirong. All rights reserved.
*/
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

class CStudent{
    public:
        int nAge;
        CStudent(){nAge = 0;}
        ~CStudent();
        
};


//========================
class CArray{
    private:
        int size;
        int *ptr;
    public:
        CArray(int s=0);
        CArray(CArray &a);
        ~CArray();
        void push_back(int v);
        CArray & operator = (const CArray &a);
        int length(){return size;}
        int & operator[] (int i){
            //非引用的函数返回值不能写在函数左边。这里返回类型设为int & ,可以实现 a[i]=4
            return ptr[i];
        }
};

//================================
class String{
    private:
        char *str;
    public:
        String():str(NULL){}//normal initialization
        const char *c_str(){return str;}
        char *operator = (const char *s);
        ~String();
        String & operator = (const String &s);
        String(String & s_in);
};

/// =======================
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