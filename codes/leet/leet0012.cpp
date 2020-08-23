/* ===========
//  * Author: Shepherd Qirong
//  * Date: 2020-04-01 23:15:46
//  * Github: https://github.com/ShepherdQR
//  * LastEditors: Shepherd Qirong
//  * LastEditTime: 2020-04-01 23:37:31
//  * Copyright (c) 2019--20xx Shepherd Qirong. All rights reserved.
*/
/*
1111. Maximum Nesting Depth of Two Valid Parentheses Strings
A string is a valid parentheses string (denoted VPS) if and only if it consists of "(" and ")" characters only, and:

It is the empty string, or
It can be written as AB (A concatenated with B), where A and B are VPS's, or
It can be written as (A), where A is a VPS.
We can similarly define the nesting depth depth(S) of any VPS S as follows:

depth("") = 0
depth(A + B) = max(depth(A), depth(B)), where A and B are VPS's
depth("(" + A + ")") = 1 + depth(A), where A is a VPS.
For example,  "", "()()", and "()(()())" are VPS's (with nesting depths 0, 1, and 2), and ")(" and "(()" are not VPS's.

 

Given a VPS seq, split it into two disjoint subsequences A and B, such that A and B are VPS's (and A.length + B.length = seq.length).

Now choose any such A and B such that max(depth(A), depth(B)) is the minimum possible value.

Return an answer array (of length seq.length) that encodes such a choice of A and B:  answer[i] = 0 if seq[i] is part of A, else answer[i] = 1.  Note that even though multiple answers may exist, you may return any of them.

 

Example 1:

Input: seq = "(()())"
Output: [0,1,1,1,1,0]
Example 2:

Input: seq = "()(())()"
Output: [0,0,0,1,1,0,1,1]
 

Constraints:

1 <= seq.size <= 10000


来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-nesting-depth-of-two-valid-parentheses-strings
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {

    }
};

*/


class SolutionW1{
public:
    vector<int> maxDepthAfterSplit(string seq){
        int d = 0;
        vector<int> ans;
        for (char & c: seq){
            if(c =='('){
                ++d;
                ans.push_back(d%2);
            }
            else{
                ans.push_back(d%2);
                --d;
            }
        }
        return ans;         
    }
};





class SolutionW2{
    public:
    vector<int> maxDepthAfterSplit(string seq){
        vector<int> ans;
        for(size_t i = 0; i< seq.size(); ++i){
            ans.push_back(i & 1 ^(seq[i] == '('));
        }
        return ans;
    }
}


public class Solution? {
    public int[] maxDepthAfterSplit(String seq) {
        int[] ans = new int [seq.length()];
        int idx = 0;
        for(char c: seq.toCharArray()) {
            ans[idx++] = c == '(' ? idx & 1 : ((idx + 1) & 1);
        }
        return ans;
    }
}



class Solution{
public:
    vector<int> maxDepthAfterSplit(string seq){
        int d = 0;
        vector<int> ans;
        for (char & c: seq){
            if(c =='('){
                ans.push_back(d & 1);
            }
            else{
                ans.push_back( (d+1) & 1);
            }
            ++d;
        }
        return ans;         
    }
};
/*
执行用时 :
4 ms, 在所有 C++ 提交中击败了88.31%的用户
内存消耗 :7.6 MB, 在所有 C++ 提交中击败了100.00%的用户

*/