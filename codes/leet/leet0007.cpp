/* ===========
//  * Author: Shepherd Qirong
//  * Date: 2020-03-13 12:21:29
//  * Github: https://github.com/ShepherdQR
//  * LastEditors: Shepherd Qirong
//  * LastEditTime: 2020-03-13 13:17:03
//  * Copyright (c) 2019--20xx Shepherd Qirong. All rights reserved.
*/

/*
169. Majority Element
Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always exist in the array.

Example 1:

Input: [3,2,3]
Output: 3
Example 2:

Input: [2,2,1,1,1,2,2]
Output: 2

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/majority-element
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


class Solution {
public:
    int majorityElement(vector<int>& nums) {

    }
};

*/
#include <iostream>
#include <vector>
using namespace std;

class SolutionWrong {
public:
    int majorityElement(vector<int>& nums) {
        if(nums.size()==1)
            return nums[0];
        int length = nums.size(), output(0);
        for(size_t i=0; i<(length/2+1); ++i){
            // i < length/2
            int temp(0);
            for(size_t j=i; j<length; ++j){
                if(nums[i]==nums[j])
                    temp +=1;
                if(temp > (length/2)){
                    output= nums[i];
                    return output;
                }
                    
            }
            
        }
        return output;
    }
};

class Solution{
    public:
        int majorityElement(vector<int> & nums){
            sort(nums.begin(), nums.end());
            return nums[nums.size()/2];
        }
};
/*
执行用时 :40 ms, 在所有 C++ 提交中击败了12.98%的用户
内存消耗 :20.4 MB, 在所有 C++ 提交中击败了5.28%的用户
*/