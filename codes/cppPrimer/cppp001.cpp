/* ===========
//  * Author: Shepherd Qirong
//  * Date: 2020-05-12 00:22:12
//  * Github: https://github.com/ShepherdQR
//  * LastEditors: Shepherd Qirong
//  * LastEditTime: 2020-08-01 22:25:45
//  * Copyright (c) 2019--20xx Shepherd Qirong. All rights reserved.
*/

/*  chapter 1
    return type, function name, parameter list, function body.
    integrated developed environment
    编译器程序将.cpp 编译生成可执行文件
    执行完后查看返回值 unix: echo $?; windows: echo %ERRORLEVEL%
    GNU编译器： g++ -o prog1 prog1.cc //其中-o后文件名，默认是windows中a.exe, unix中a.out.  警告有问题的程序 /-Wall
    visual studio 2010: c1 /EHsc prog1.cpp, 默认生成prog1.exe. 警告有问题的程序 /W4
    一个表达式(expression)产生一个计算结果
    endl, manipulator操纵符。结束当前行，将设备关联的缓冲区buffer中的内容刷新到设备中，保证从内存中写入到输出流中。
    ++x 前缀递增

    输入数据的结束键， windows: ctrl+z then enter or return; unix: ctrl+d
    edit-compile-debug
    main的形参列表后第一个非空、非注释的字符需要是{
*/

#include <iostream>// cout cin cerr clog
#include <string>
#include <vector>
#include<ctime>

#include "Sales_item.h"
#include "CPPPChapter01.h"
using namespace std;







//

int main(int argc, char ** argv){
    
    time_t timeLocal99=time(NULL);
    char timeCurrent99[64];
    strftime(timeCurrent99, sizeof(timeCurrent99), "%Y%m%d-%H%M%S",localtime(&timeLocal99));
    string timeCurrent = timeCurrent99;
    cout << timeCurrent << endl;

    //==============
        /*
        Sum2Nums1_1();
        //ContinueCounting1_2();//input 42 42 55 55 6 100 100 100 z [enter]ClassIndexBook1_3();

        */
       
       

    

    

    return 0;
}

