/* ===========
//  * Author: Shepherd Qirong
//  * Date: 2020-03-09 19:25:01
//  * Github: https://github.com/ShepherdQR
//  * LastEditors: Shepherd Qirong
//  * LastEditTime: 2020-03-09 20:59:56
//  * Copyright (c) 2019--20xx Shepherd Qirong. All rights reserved.
*/

/*121. Best Time to Buy and Sell Stock

Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction (i.e., buy one and sell one share of the stock), design an algorithm to find the maximum profit.

Note that you cannot sell a stock before you buy one.

Example 1:

Input: [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
             Not 7-1 = 6, as selling price needs to be larger than buying price.
Example 2:

Input: [7,6,4,3,1]
Output: 0
Explanation: In this case, no transaction is done, i.e. max profit = 0.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


class Solution {
public:
    int maxProfit(vector<int>& prices) {

    }
};
*/
#include<iostream>
#include<cmath>
using namespace std;

//  ----step  1 -----------------
class Solution1 {
public:
    int maxProfit(vector<int>& prices) {
        int outPut(0), length = prices.size();
        for(size_t i=0; i<length; ++i){
            for(size_t j=i+1; j<length; ++j){
                if(prices[j]- prices[i]> outPut)
                    outPut = prices[j]- prices[i];
            }
        }
        return outPut;
    }
};
/*
执行用时 :1104 ms, 在所有 C++ 提交中击败了12.91%的用户
内存消耗 :14.6 MB, 在所有 C++ 提交中击败了5.09%的用户
*/
//==========================================




//  ----step  2 -----------------
/*
动态规划 前i天的最大收益 = max{前i-1天的最大收益，第i天的价格-前i-1天中的最小价格}
DP的思路： 利用原问题与子问题的关系，将其变成 大问题的解 = 小问题的解的函数， 从而将问题变成size的扩展。

1) 定义状态和设计转移方程、、、、定义状态：定义一个状态，例如f(i) = 到a[i]为止到最小值；设计转移方程：根据如上状态方程定义，则有 f(i+1) = min(f(i), a[i+1])
2）设置初始条件，迭代初值。
3）特殊处理某些迭代步骤，如开始和结束时。

*/

class Solution2 {
public:
    int maxProfit(vector<int>& prices) {
        int length = prices.size();
        if(length==0) return 0;
        int minNum=prices[0], output(0);
        for(size_t i=1; i<length-1; ++i){
            if(prices[i]>minNum){
                if(prices[i]-minNum > output){
                    output = prices[i]-minNum;
                }                    
            }               
            else{
                minNum = prices[i];
            }                
        }
        return output;
    }
};// if...else remember to add {}
/*
执行用时 :8 ms, 在所有 C++ 提交中击败了78.91%的用户
内存消耗 :14.3 MB, 在所有 C++ 提交中击败了5.09%的用户
*/





//  ----step  3 ------modified based on 2
class Solution3 {
public:
    int maxProfit(vector<int>& prices) {
        int length = prices.size();
        if(length < 2) return 0;//length=1 also get 0
        int minNum=prices[0], output(0);
        for(size_t i=1; i<length; ++i){
            if(prices[i]<minNum){
                minNum = prices[i];
            }//two different judges, easy one first
            else if(prices[i]-minNum > output){
                output = prices[i]-minNum;
            }               
        }
        return output;
    }
};
/*
执行用时 :4 ms, 在所有 C++ 提交中击败了97.84%的用户
内存消耗 :14.6 MB, 在所有 C++ 提交中击败了5.09%的用户
*/




//  ----step  4  ----  try the fastest
// others run 0 ms, while i run slowly
class Solution4{
    public:
        int maxProfit(vector<int>& prices){
            int length = prices.size();
            int dp_i0 = 0, dp_i1 = INT32_MIN;
            for (size_t i = 0; i < length; ++i){
                dp_i0 = max(dp_i0, dp_i1 + prices[i]);
                dp_i1 = max(dp_i1, -prices[i]);
            }
            return dp_i0;
        }
};
/*
执行用时 :16 ms, 在所有 C++ 提交中击败了26.45%的用户
内存消耗 :14.1 MB, 在所有 C++ 提交中击败了5.09%的用户
*/



//  ----step  5  ----  try the lest memory cost
// the top few of the lestest memory cost method using two for process. while i run this one
// others run using 9256kb.
class Solution5{
    public:
        int maxProfit(vector<int>& prices){
            int dp_i0 = INT_MAX;
            int dp_i1 = 0;
            for(int i:prices){
                // c++11 usage
                dp_i0 = min(i, dp_i0);
                dp_i1 = max(dp_i1, i-dp_i0);//easier to understand.
            }
            return dp_i1;
        }
};
/*
执行用时 :8 ms, 在所有 C++ 提交中击败了78.91%的用户
内存消耗 :14.3 MB, 在所有 C++ 提交中击败了5.09%的用户
*/
