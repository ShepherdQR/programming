<!--
 * @Author: Shepherd Qirong
 * @Date: 2020-08-08 17:47:53
 * @Github: https://github.com/ShepherdQR
 * @LastEditors: Shepherd Qirong
 * @LastEditTime: 2020-08-19 21:58:03
 * @Copyright (c) 2019--20xx Shepherd Qirong. All rights reserved.
-->
<!-- UTF8 -->

# STL-IO

A buffer is a block of memory used as an intermediate, temporary storage facility for the transfer of information from a device to a program or from a program to a device.
Typically, devices such as disk drives transfer information in blocks of 512 bytes or more, whereas programs often process information 1 byte at a time.
T buffer helps match these two disparate rates of information transfer.

A stream acts as an intermediary between the program and the stream's source or destination.



read cin and program ends unnormally, will refresh cout

program <--- stream ---> output

Loading from the memory is faster than loading from the hardware.

刷新缓冲区 flushing the buffer, like pulling down the ENTER in cin.

const char *a = "hi", *b = "hello";//Here the data stored in memory is hi\0hello
cout.write(a,4);// so the output is hi\0h

long val = 555555555;
cout.write((char*)&val, sizeof long);//long is 4 bytes, transform as 4 char, so displays as random things.

输入输出重定向, Text <fileIN.txt> out.txt

ofstream& operator<< (int);//插入操作符被重载，可识别所有基本类型，可识别的指针类型为：
const signed char*; const unsigned char*;
const char*; void*

char* hi = "hi";
cout << hi << (void*)hi << endl;

cout.put('w');//display char
cout.put(65.3);//display A
cout.write(hi); // display char*