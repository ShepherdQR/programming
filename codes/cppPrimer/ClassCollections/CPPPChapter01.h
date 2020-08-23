/* ===========
//  * Author: Shepherd Qirong
//  * Date: 2020-08-01 21:17:51
//  * Github: https://github.com/ShepherdQR
//  * LastEditors: Shepherd Qirong
//  * LastEditTime: 2020-08-01 22:23:15
//  * Copyright (c) 2019--20xx Shepherd Qirong. All rights reserved.
*/
//coding UTF-8
#ifndef CPPCHAPTER01_H
#define CPPCHAPTER01_H

#include<iostream>
#include<string>

using namespace std;
int sumAB(const int xLeft, const int xRight);


//s03 classIndexBook1_3(){}
void ClassIndexBook1_3(){

    Sales_item bookIn, bookSum;
    vector< Sales_item> book, book2;

    while(cin >> bookIn){
        cout << bookIn << endl;
        book.push_back(bookIn);
        bookSum += bookIn;
    }
    cout << bookSum << endl;//文件重定向 ./main <./Datasets/testInBooks.qr> testOut.qr

    int indexBook2(0);
    vector<int> ifok(book.size(), 1);
    for(size_t i=0; i< book.size(); ++i){
        //Sales_item bookCur = book[i];
        if(ifok[i] ){
            book2.push_back(book[i]);
            ++indexBook2;
        }

        for(size_t j=i+1; j< book.size(); ++j){
            if((book[i].isbn()== book[j].isbn()) & ifok[j]  ){
                book2[indexBook2-1] += book[j];
                ifok[j] = 0;
            }
        }
    }
    cout << "== sum of the sell records with the same ISBN:" << endl;
    for(size_t i=0; i< book2.size(); ++i){
        cout << book2[i] << endl;
    }

}


// s02 continueCounting
void ContinueCounting1_2(){
    int valin2(0), valin3(0);
    if(std::cin >>valin2){
        int cnt = 1;
        while(std::cin >> valin3){
            if(valin3 == valin2){
                ++ cnt;
            }else{
                cout << valin2 << ", " << cnt << endl;
                valin2 = valin3;
                cnt = 1;
            }
        }
        cout << valin2 << ", " << cnt << endl;
    }
}






// s01 add numbers
void Sum2Nums1_1(){
    cout << "Input two numbers(double) to sum" << endl;// 字符串字面值常量 string literal
    double x1(0),x2(0);
    cin >> x1 >> x2;
    cout << x1 << " + " << x2 << " = " << x1 + x2 << endl;

// 2 ++x and --x
    sumAB(x1, x2);

    int out1(0);
    for(int i=-100; i<=100; ++i) out1+=i;
    cout << out1 << "==" << endl;

// 3 continue in without given the number
    int xIn(0), xOut(0), xNum(0);
    while(std::cin >> xIn){
        xOut += xIn;
        ++xNum;
    }
    cout << " The sum of the input numbers is: " << xOut << ", and the average is: " << xOut/xNum << endl;

}
int sumAB(const int xLeft, const int xRight){
    if(xLeft == xRight) return xRight;
    int x1 = xLeft, x2 = xRight;
    
    int sum(x1), val(x1);
    while((val < x2) & (x1<x2)){
        ++val;
        sum += val;
    }
    while((val > x2) & (x1>x2)){
        --val;
        sum += val;
    }

    cout << "total: " << sum << endl;
    return sum;
}





#endif