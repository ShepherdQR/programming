/* ===========
//  * Author: Shepherd Qirong
//  * Date: 2020-03-16 14:46:54
//  * Github: https://github.com/ShepherdQR
//  * LastEditors: Shepherd Qirong
//  * LastEditTime: 2020-03-16 15:48:38
//  * Copyright (c) 2019--20xx Shepherd Qirong. All rights reserved.
*/
/*
面试题 01.06. Compress String LCCI
Implement a method to perform basic string compression using the counts of repeated characters. For example, the string aabcccccaaa would become a2blc5a3. If the "compressed" string would not become smaller than the original string, your method should return the original string. You can assume the string has only uppercase and lowercase letters (a - z).

Example 1:

Input: "aabcccccaaa"
Output: "a2b1c5a3"
Example 2:

Input: "abbccd"
Output: "abbccd"
Explanation: 
The compressed string is "a1b2c2d1", which is longer than the original string.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/compress-string-lcci
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
class Solution {
public:
    string compressString(string S) {

    }
};
*/


//  --- step 1 -------
class Solution1 {
public:
    string compressString(string S) {
        int length=S.size(), lengthTmp(1);
        if(length <3) return S;
        string output="";
        char tmp=S[0];
        for(int i=1; i<length; ++i){           
            if(tmp != S[i]){
                output += tmp;
                output += std::to_string(lengthTmp);
                tmp = S[i];
                lengthTmp =1;
            }
            else{
                lengthTmp +=1;
            }
            if(i == length-1){
                output += tmp;
                output += std::to_string(lengthTmp);
            }
        }
        if(output.size()< length)
            return output;
        else 
            return S;
    }
};
/*
执行用时 :24 ms, 在所有 C++ 提交中击败了10.24%的用户
内存消耗 :8.9 MB, 在所有 C++ 提交中击败了100.00%的用户
*/



class Solution2 {
public:
    string compressString(string S) {
        int length=S.size(), lengthTmp(1);
        if(length <3) return S;
        string output="";
        char tmp=S[0];
        for(int i=1; i<length; ++i){           
            if(tmp == S[i])
                lengthTmp +=1;
            else{
                output += tmp + std::to_string(lengthTmp);
                tmp = S[i];
                lengthTmp =1;
            }           
        }
        output += tmp + std::to_string(lengthTmp);
        return output.size()< length ? output: S;
    }
};
/*
执行用时 :20 ms, 在所有 C++ 提交中击败了20.31%的用户
内存消耗 :8.7 MB, 在所有 C++ 提交中击败了100.00%的用户
*/



//----------step3 ---good ---  using ss , is it faster?
// time O(n); space O(1); // 1 circle;
class Solution {
public:
    string compressString(string S) {
        static auto speedup = [](){ios::sync_with_stdio(false);cin.tie(nullptr);return nullptr;}();// fast?

        if(S.size()< 3) return S;
        string output="";
        char tmp=S[0];
        int lengthTmp(1);
        ostringstream ss;

        for(int i=1; i<S.size(); ++i){           
            if(tmp == S[i]){
                lengthTmp +=1;
                continue;
            }           
            ss << tmp << lengthTmp;
            tmp = S[i];
            lengthTmp =1;            
        }
        ss << tmp << lengthTmp;
        output = ss.str();
        if(output.size()< S.size())
            return output;
        return S;
    }
};
/*
执行用时 :4 ms, 在所有 C++ 提交中击败了99.83%的用户
内存消耗 :9 MB, 在所有 C++ 提交中击败了100.00%的用户
*/