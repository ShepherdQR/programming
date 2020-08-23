/* ===========
//  * Author: Shepherd Qirong
//  * Date: 2020-08-02 21:25:10
//  * Github: https://github.com/ShepherdQR
//  * LastEditors: Shepherd Qirong
//  * LastEditTime: 2020-08-02 22:51:04
//  * Copyright (c) 2019--20xx Shepherd Qirong. All rights reserved.
*/

#include<iostream>
#include<vector>
#include<string>
using namespace std;

#include"e001Matrix.h"

int main( ){
    string fileNameIn = "../ClassCollections/e001Matrix.txt", fileNameOut = "../ClassCollections/e001MatrixOutput.txt";
    int row(2), col(5);
    matrixIO(fileNameIn, fileNameOut, row, col);

    return 0;
}