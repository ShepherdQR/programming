/* ===========
//  * Author: Shepherd Qirong
//  * Date: 2020-03-11 22:13:44
//  * Github: https://github.com/ShepherdQR
//  * LastEditors: Shepherd Qirong
//  * LastEditTime: 2020-03-12 00:44:08
//  * Copyright (c) 2019--20xx Shepherd Qirong. All rights reserved.
*/

/*
1013. Partition Array Into Three Parts With Equal Sum

Given an array A of integers, return true if and only if we can partition the array into three non-empty parts with equal sums.

Formally, we can partition the array if we can find indexes i+1 < j with (A[0] + A[1] + ... + A[i] == A[i+1] + A[i+2] + ... + A[j-1] == A[j] + A[j-1] + ... + A[A.length - 1])

 

Example 1:

Input: A = [0,2,1,-6,6,-7,9,1,2,0,1]
Output: true
Explanation: 0 + 2 + 1 = -6 + 6 - 7 + 9 + 1 = 2 + 0 + 1
Example 2:

Input: A = [0,2,1,-6,6,7,9,-1,2,0,1]
Output: false
Example 3:

Input: A = [3,3,6,5,-2,2,5,1,-9,4]
Output: true
Explanation: 3 + 3 = 6 = 5 - 2 + 2 + 5 + 1 - 9 + 4
 

Constraints:

3 <= A.length <= 50000
-10^4 <= A[i] <= 10^4

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/partition-array-into-three-parts-with-equal-sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& A) {

    }
};

*/
#include <vector>
#include <iostream>
using namespace std;

//  step 01 ------ wrong
class SolutionWrong {
    // also i found this method ,  if ...plus... is the right choice is difficult to handle.
public:
    bool canThreePartsEqualSum(vector<int>& A) {
        int length_all = A.size();
        if(length_all <=6) return false;
        int sum_all = 0;
        for(size_t i=0; i<length_all; ++i){
            sum_all += A[i];
        }
        if(sum_all %3 !=0) return false;
        //cout << sum_all << endl;

        int sum_left(0), sum_right(0);
        int length_left(0), length_right(0);
        for(size_t i=0; i<length_all && sum_left!= sum_all/3;++i){
            sum_left +=A[i];
            length_left += 1;
            }
        if(length_left== length_all)
            return false;
        for(size_t i=length_left; i<length_all-1 && sum_right!= sum_all/3;++i){
            sum_right +=A[i];
            length_right += 1;
            }
        if(length_right== length_all)
            return false;
        //cout << length_left<<",,," << length_right << endl;    
        if(length_left==0 || length_right==0 ||length_all -length_left-length_right==0){
            return false;
        }
        if(length_left != length_right ||length_left != length_all -length_left-length_right || length_right != length_all -length_left-length_right ){
            return true;
        }
        else{return false;}
    }
};

//  step 02----  not finished.
class SolutionWrong2 {
    // at the very begining, I thought about this.
public:
    bool canThreePartsEqualSum(vector<int>& A){
        int length = A.size();
        int tmp(0);
        vector<int> values(length);
        for (size_t i=0; i< length; ++i){
            tmp+=A[i];
            values.push_back(tmp);
        }
 // all of a sudden i found that i misunderstood the question.  the question is solved only if a partition is found, no need to be with rifferent size.
    }
};





//  step 03---- finally
class Solution1 {
public:
    bool canThreePartsEqualSum(vector<int>& A) {
        int length_all = A.size(), sum_all(0);
        for(size_t i =0; i< length_all; ++i){
            sum_all+=A[i];
        }
        if(sum_all%3 !=0) return false;

        int sum_1(0), sum_2(0);
        int length1(0),length2(0);
        for(size_t i =0; i< length_all ; ++i){
            sum_1 += A[i];
            length1 +=1;
            if(sum_1 == sum_all/3){
                for(size_t j =length1; j< length_all ; ++j){
                    sum_2 += A[j];
                    length2 +=1;
                    //cout << length1<<",,,"<< length2<< endl;
                    if(sum_2 == sum_all/3 && length1+ length2 < length_all){
                        return true;
                    }
                }
                return false;
            }   
        }
        return false;       
    }
};
/*
执行用时 :96 ms, 在所有 C++ 提交中击败了8.29%的用户
内存消耗 :32.2 MB, 在所有 C++ 提交中击败了5.26%的用户
*/

//finally it works.


//  step 04 -speed up
class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& A) {
        int length = A.size(), sum(0);
        for(size_t i =0; i< length; ++i){
            sum+=A[i];
        }
        if(sum %3 !=0)
            return false;
        
        int sum_tmp=A[0],flag(0);
        for(size_t i =1; i< length ; ++i){
            cout <<i<<", "<<A[i]<<", "<< sum_tmp <<", "<< flag<< endl;
            if(sum_tmp == (sum/3)){
                sum_tmp =A[i];
                flag+=1;
                if(flag == 2)
                    return true;
            }
            else if(flag <2)
                sum_tmp+=A[i];            
        }
        return false; 
    }
};
/*
执行用时 :52 ms, 在所有 C++ 提交中击败了92.75%的用户
内存消耗 :31.9 MB, 在所有 C++ 提交中击败了5.26%的用户
*/





int main(){
    //vector<int> aa = {0,2,1,-6,6,7,9,-1,2,0,1};
    //vector<int> aa = {14,6,-10,2,18,-7,-4,11};
    //vector<int> aa = {0,2,1,-6,6,-7,9,1,2,0,1};
    //vector<int> aa = {1,-1,1,-1};
    //vector<int> aa = {1,-1,1,-1,1,-1,1,-1};
    vector<int> aa = {18,12,-18,18,-19,-1,10,10};
    //vector<int> aa = {14,6,-10,2,18,-7,-4,11};



    Solution ss;
    cout << ss.canThreePartsEqualSum(aa) << endl;
}