/* ===========
//  * Author: Shepherd Qirong
//  * Date: 2020-02-19 23:21:42
//  * Github: https://github.com/ShepherdQR
//  * LastEditors: Shepherd Qirong
//  * LastEditTime: 2020-02-23 21:12:26
//  * Copyright (c) 2019--20xx Shepherd Qirong. All rights reserved.
*/
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
#include<string.h>// declear strlen and  strcpy
#include "exerciseClass.h"
using namespace std;












//ostream & ostream::operator<< (const CStudent & student){
//    return *this.nAge;}

ostream & operator<< (ostream & o, const CStudent & s){
    o << s.nAge;
    return o;
}


//========================
CArray::CArray(int s):size(s){
    if(s == 0)
        ptr = NULL;
    else
        ptr = new int[s];
}
CArray::CArray(CArray & a){
    if(!a.ptr){
        ptr = NULL;
        size = 0;
        return; 
    }
    ptr = new int[a.size];
    memcpy(ptr, a.ptr, sizeof(int)* a.size);
    size = a.size;
}
CArray::~CArray(){
    if(ptr) delete []ptr;
}
CArray & CArray::operator = (const CArray &a){
    if(ptr == a.ptr)
        return *this;
    if(a.ptr == NULL){
        if(ptr) delete []ptr;
        ptr = NULL;
        size = 0;
        return *this;
    }
    if(size < a.size){
        //空间足够大，不必新开辟空间
        if(ptr)
            delete []ptr;
        ptr = new int[a.size];
    }
    memcpy(ptr, a.ptr, sizeof(int)*a.size);
    size = a.size;
    return *this;
}
void CArray::push_back(int v){
    if(ptr){
        int *tmpPtr = new int[size+1];
        memcpy(tmpPtr, ptr, sizeof(int)*size);
        delete []ptr;
        ptr = tmpPtr;
    }
    else
        ptr = new int[1];
    ptr[size++] = v;
}











//==============================
char *String::operator = (const char *s){
    if(str)
        delete []str;
    if(s){
        str = new char[strlen(s)+1];
        strcpy(str, s);
    }
    else{
        str = NULL;
    }
    return str;
}
String::~String(){
    if(str)
        delete []str;
}

String & String::operator = (const String &s){
    // 返回值void不好，因为void在a=b=c会出错。
    // 用 String &会更好保持复制号原本的特性。
    if(str == s.str){
        return *this;
    }
    if(str){
        delete []str;
    }
    if(s.str){
        str = new char[strlen(s.str)+1];
        strcpy(str, s.str);
    }
    else{
        str = NULL;
    }
    return *this;
}

String::String(String & s_in){
    if(s_in.str){
        str = new char[strlen(s_in.str)+1];
        strcpy(str, s_in.str);
    }
    else
    {
        str = NULL;
    }
    
}






/// =======================
void C1::GetValue() const{
    //value = 0;// wrong
    //func();// wrong
    cout << "C1::GetValue() is called" << endl;
}