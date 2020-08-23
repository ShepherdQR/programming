/* ===========
//  * Author: Shepherd Qirong
//  * Date: 2020-07-08 09:35:11
//  * Github: https://github.com/ShepherdQR
//  * LastEditors: Shepherd Qirong
//  * LastEditTime: 2020-07-08 09:58:25
//  * Copyright (c) 2019--20xx Shepherd Qirong. All rights reserved.
*/
/*
面试题 16.11. Diving Board LCCI
You are building a diving board by placing a bunch of planks of wood end-to-end. There are two types of planks, one of length shorter and one of length longer. You must use exactly K planks of wood. Write a method to generate all possible lengths for the diving board.

return all lengths in non-decreasing order.

Example:

Input: 
shorter = 1
longer = 2
k = 3
Output:  {3,4,5,6}
Note:

0 < shorter <= longer
0 <= k <= 100000

*/
#include<vector>


class Solution {
public:
    vector<int> divingBoard(int shorter, int longer, int k) {
        
        vector<int> out;
        if(k==0) return out;//m1
        if(shorter == longer){//m2
            out.push_back(shorter*k);
            return out;
        }
        for(int i=0;i<=k;++i){
            out.push_back(longer * i + shorter * (k-i));
        }
        //if(k==0) out.push_back(0);//m1xx
        return out;

    }
};
/*
执行用时：28 ms, 在所有 C++ 提交中击败了60.46%的用户
内存消耗：20.2 MB, 在所有 C++ 提交中击败了100.00%的用户

*/

