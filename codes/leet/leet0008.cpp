/* ===========
//  * Author: Shepherd Qirong
//  * Date: 2020-03-14 14:53:30
//  * Github: https://github.com/ShepherdQR
//  * LastEditors: Shepherd Qirong
//  * LastEditTime: 2020-03-14 15:10:09
//  * Copyright (c) 2019--20xx Shepherd Qirong. All rights reserved.
*/
/*
300. Longest Increasing Subsequence
Given an unsorted array of integers, find the length of longest increasing subsequence.

Example:

Input: [10,9,2,5,3,7,101,18]
Output: 4 
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4. 
Note:

There may be more than one LIS combination, it is only necessary for you to return the length.
Your algorithm should run in O(n2) complexity.
Follow up: Could you improve it to O(n log n) time complexity?

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-increasing-subsequence
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {

    }
};
*/


class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int length = nums.size();
        if(length == 0)
            return 0;
        vector<int> dp(length,0);
        for(size_t i=0; i<length; ++i){
            dp[i] = 1;
            for(size_t j=0; j< i; ++j){
                if(nums[j] < nums[i]){
                    dp[i]=max(dp[i],dp[j]+1);
                }
            }
        }
        return *max_element(dp.begin(),dp.end());
    }
};
/*
执行用时 :52 ms, 在所有 C++ 提交中击败了53.23%的用户
内存消耗 :9.2 MB, 在所有 C++ 提交中击败了5.07%的用户
*/


