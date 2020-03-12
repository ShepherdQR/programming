/* ===========
//  * Author: Shepherd Qirong
//  * Date: 2020-03-12 01:23:43
//  * Github: https://github.com/ShepherdQR
//  * LastEditors: Shepherd Qirong
//  * LastEditTime: 2020-03-12 01:40:46
//  * Copyright (c) 2019--20xx Shepherd Qirong. All rights reserved.
*/

#include <iostream>
#include "./ClassCollections/ska_unordered_map.hpp"
using namespace std;


int main(){
    ska::unordered_map<int,string> unomap ={{1,"dd"},{2,"ssss"}};
    for(auto x: unomap){
        cout<<unomap[x.first]<<endl;
        cout<<x.second<<endl;//以value值输出
    }

    //myMap.insert(pair<int, string>(3,"陈二"));//插值用pair的形式
    //myMap.insert(pair<int,string>(3,"陈二"));
    //myMap[2]="daf";
    return 0;

}



