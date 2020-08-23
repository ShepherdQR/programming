/* ===========
//  * Author: Shepherd Qirong
//  * Date: 2020-08-02 22:03:21
//  * Github: https://github.com/ShepherdQR
//  * LastEditors: Shepherd Qirong
//  * LastEditTime: 2020-08-02 22:59:27
//  * Copyright (c) 2019--20xx Shepherd Qirong. All rights reserved.
*/
#ifndef E001_MATRIX_H
#define E001_MATRIX_H

#include<iostream>
#include<fstream>

using namespace std;


void matrixIO(string fileNameIn, string fileNameOut, int row, int col){
    //cout << "hi" << endl;

    const char* fileName = fileNameIn.data();
    const char* fileNameSaved = fileNameOut.data();
    ifstream fileIn;
    fileIn.open(fileName);
    if(!fileIn.is_open()){
        cout << fileName << endl;
        cerr<< "The file cannot be read." << endl;
    }
    int **ppArray(NULL);
    ppArray = new int*[row];
    for(int i=0;i<row;++i){
        ppArray[i] = new int[col];
    }
    

    int countNums(0);
    while(!fileIn.eof()){
        if(countNums== col*row){break;}
        fileIn>>ppArray[countNums/col][countNums%col];
        //cout << fileName << ppArray[countNums/col][countNums%col]<< endl;
        ++countNums;
    }
    fileIn.close(); 
    cout << "The total numbers in the matrix is: " << countNums << endl;
   

    

    ofstream fileOut;
    fileOut.open(fileNameSaved);
    if(!fileOut.is_open()){
        cout << fileNameSaved << endl;
        cerr<< "The file cannot be read." << endl;
    }
    for(int i=0;i<countNums;++i){
        cout << ppArray[i/col][i%col]<<' ';
        fileOut << ppArray[i/col][i%col] << ' ';
        if(i%col==col-1){
            cout << endl;
            fileOut << endl;
        }

    }
    fileOut.close();


    for(int i=0;i<row;++i){
        delete[] ppArray[i];
    }
    delete[] ppArray;

}

#endif