/*
1. Two Sum

Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:

Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/two-sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
    }
};


*/



// s01, first by myself
class Solution1 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int length = nums.size();
        int ok = 0;
        vector<int> output;

        for (size_t i = 0; i!=length && ok==0; ++i){
            for (size_t j = i+1; j!=length && ok==0; ++j){
                if(nums[i]+nums[j] == target){
                    output.push_back(i);
                    output.push_back(j);
                    ok =1;
                }
            
            }
        }
        return output;
    }
};
/*
执行用时 :252 ms, 在所有 C++ 提交中击败了19.94%的用户
内存消耗 :9.5 MB, 在所有 C++ 提交中击败了48.31%的用户

*/



// s02, hash, not fully understood ?
class Solution2 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> table;
        vector<int> output(2,-1);

        for (size_t i =0; i != nums.size(); ++i){
            table.insert(map<int,int>::value_type(nums[i],i));
        }

        for (size_t i =0; i != nums.size(); ++i){
            if(table.count(target - nums[i]) >0 && table[target - nums[i]] != i){
                output[0] = i;
                output[1] = table[target - nums[i]];
                break;
            }
        }
        return output;
    }
};
/*
执行用时 :8 ms, 在所有 C++ 提交中击败了96.82%的用户
内存消耗 :10.7 MB, 在所有 C++ 提交中击败了5.01%的用户
*/



// s03, hash, not fully understood ?
class Solution3 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> table;
        vector<int> output(2,-1);

        for (size_t i =0; i != nums.size(); ++i){
            if(table.count(target - nums[i]) >0){
                output[1] = i;
                output[0] = table[target - nums[i]];
                break;
            }
            table[nums[i]] = i;
        }
        return output;
    }
};
/*
执行用时 :12 ms, 在所有 C++ 提交中击败了93.95%的用户
内存消耗 :10.4 MB, 在所有 C++ 提交中击败了9.84%的用户
*/



// s04, hash, official 4ms, modified from s03 ?
class Solution4 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> table;

        for (size_t i =0; i != nums.size(); ++i){
            if(table.count(target - nums[i]) ){
                return{table[target - nums[i]], i};
            }
            table[nums[i]] = i;
        }
        return {0, 0};
    }
};
/*
while is map:
有序，是红黑树
执行用时 :16 ms, 在所有 C++ 提交中击败了65.12%的用户
内存消耗 :10.3 MB, 在所有 C++ 提交中击败了11.83%的用户

while is unordered_map:
哈希表，是无序的
执行用时 :4 ms, 在所有 C++ 提交中击败了99.74%的用户
内存消耗 :10.3 MB, 在所有 C++ 提交中击败了12.56%的用户
*/



// s05, hash, official 0ms, no idea..?
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int arrLenMax = 2047;
        int hashArray[arrLenMax + 1];
        memset(hashArray, 0, sizeof(hashArray));
        for (int i=0; i<nums.size(); ++i) {
            int diff = target - nums[i];
            if (hashArray[diff & arrLenMax] != 0) {
                return {hashArray[diff & arrLenMax] - 1, i};
            }
            hashArray[nums[i] & arrLenMax] = i + 1;
        }
        return {0, 0};
    }
};