/* ===========
//  * Author: Shepherd Qirong
//  * Date: 2020-02-25 16:38:46
//  * Github: https://github.com/ShepherdQR
//  * LastEditors: Shepherd Qirong
//  * LastEditTime: 2020-02-25 18:05:36
//  * Copyright (c) 2019--20xx Shepherd Qirong. All rights reserved.
*/

void captureTime(const float lx, const float ly, const float vx, const float vy, const float k, const float speed, const float pic_time,
float out_number, float out_length);


#include<iostream>
#include<stdio.h>
#include <math.h>
using namespace std;
float out_numberco[3]={0},out_lengthco[3]={0};


int main(){

    double a =3.1;
    cout << ceil(a) << endl << a << endl;
    // total = 2 *(side + top_hf + 2* front_hf)
    //side, top_hf, front_hf
    float lxco[3]={12, 12, 3};
    float lyco[3]={4, 3, 4};
    float vx = 0.68, vy = 0.42;
    float k = 0.8;// 不重合率0.8，重合率0.2
    float speed = 0.15;//0.3m/s
    float pic_time1 = 1;

    for (int i =0; i<3; ++i){
        float out_numberco1, out_lengthco1;
        captureTime(lxco[i], lyco[i], vx,  vy, k, speed, pic_time1, 
        out_numberco1, out_lengthco1);
        out_numberco[i]= out_numberco1;
        out_lengthco[i]=out_lengthco1;
    }


    float all_number, all_time_path, all_time_capture, all_time_all;

    all_number = 2*(out_numberco[0] + out_numberco[1] + 2 *out_numberco[2] );
    // 2*(420+308+2*90) = 2*908 = 1816
    all_time_capture = all_number * 2/2;

    all_time_path =  2*(out_lengthco[0] + out_lengthco[1] + 2 *out_lengthco[2] )/speed/2;
    all_time_all = all_time_capture + all_time_path;
    cout << "Total viewpoint number is: "<< all_number << endl;
    cout << "Time to capture is: "<< all_time_capture << endl;
    cout << "Time to move is: "<< all_time_path <<" speed: " << speed << endl;
    cout << "Total time is: "<< all_time_all <<" speed: " << speed << endl;

/*
k=.8 
Number: 231
Length: 81.44
============

Number: 168
Length: 60.272
============

Number: 55
Length: 18.976


    2*(231+168+2*55) = 2*509 
    拍照时间1s，有需要 2*8.5min，并行需要8.5min
    2*(81.5+60.3+2*19) = 2*179.8
    速度0.15m/s, 2*1198.7 = 20min
    速度0.2m/s， 2*899 = 15.0分



*/



    
    

    cout << "ok" << endl;


    





    return 0;
}



void captureTime(const float lx, const float ly, const float vx, const float vy, const float k, const float speed, const float pic_time,
  float out_number, float  out_length){
    float nx, ny, dx, dy, time_d, time_cap;

    nx = ceil( (lx - vx)/(k * vx) );
    ny = ceil( (ly - vy)/(k * vy) );
    out_number = nx * ny;
    cout << "Number: " << out_number << endl;


    dx = (nx - 1)* k * vx * ny + (ny - 1)* k * vy;
    dy = (ny - 1)* k * vy * nx + (nx - 1)* k * vx;
    out_length = dx;
    if(out_length > dy)
        out_length = dy;

    cout << "Length: " << out_length << endl;
    cout << "============" << endl << endl;

}