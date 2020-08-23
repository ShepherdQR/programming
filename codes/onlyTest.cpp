/* ===========
//  * Author: Shepherd Qirong
//  * Date: 2020-03-23 20:08:58
//  * Github: https://github.com/ShepherdQR
//  * LastEditors: Shepherd Qirong
//  * LastEditTime: 2020-08-23 22:44:00
//  * Copyright (c) 2019--20xx Shepherd Qirong. All rights reserved.
*/

#include <iostream>
#include <ctime>
#include <fstream>
#include <random>
#include <string>
using namespace std;

#include"./ClassCollections/Complex.h"
 

void randomList(float xOut[], int numIn, float rangeL, float rangeR, int seedIn =1);
void ininitial();
void delayTIme(const double delayTime){
    clock_t time1 = clock();
    clock_t delay = delayTime * CLOCKS_PER_SEC;
    while(clock()-time1< delay);
    cout << "THe system has been delayed for " <<  delayTIme << " seconds." << endl;
}

int main(){
    
    ininitial();
    //delayTIme(1.2);

    Complex c1, c2(1);
    cout << c1 << c2 << endl;

    


 






    return 0;
}




//==========
void randomList(float xOut[], int numIn, float rangeL, float rangeR, int seedIn){
    default_random_engine engienR(seedIn);
    uniform_real_distribution<float> u(0, (rangeR - rangeL));
    for(size_t i = 0; i< numIn; ++i){//(sizeof(xOut)/sizeof(xOut[0]))
        xOut[i] = u(engienR);
    }
}
void ininitial(){
    int seedRandom = 4, freedom6(6);
    float xOut[freedom6];
    randomList(xOut, freedom6, -1.5,  1.5);
    for(int i=0; i< freedom6; ++i){
        cout << xOut[i] << ' ';
    }cout << endl;


    time_t timeLocal99 = time(0);
    char timeOri[20];
    strftime(timeOri, sizeof(timeOri), "%Y%m%d-%H%M%S",localtime(&timeLocal99));
    
    string fileName99 = "logs";
    ofstream outFile("../logs/" + fileName99 + timeOri);
    outFile << timeOri << endl;
    outFile.close();
    cout << "============" << timeOri << "============"<< endl;
}