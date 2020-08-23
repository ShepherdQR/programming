/* ===========
//  * Author: Shepherd Qirong
//  * Date: 2020-03-17 12:23:30
//  * Github: https://github.com/ShepherdQR
//  * LastEditors: Shepherd Qirong
//  * LastEditTime: 2020-03-17 13:31:40
//  * Copyright (c) 2019--20xx Shepherd Qirong. All rights reserved.
*/

/*
1160. Find Words That Can Be Formed by Characters

You are given an array of strings words and a string chars.

A string is good if it can be formed by characters from chars (each character can only be used once).

Return the sum of lengths of all good strings in words.

 

Example 1:

Input: words = ["cat","bt","hat","tree"], chars = "atach"
Output: 6
Explanation: 
The strings that can be formed are "cat" and "hat" so the answer is 3 + 3 = 6.
Example 2:

Input: words = ["hello","world","leetcode"], chars = "welldonehoneyr"
Output: 10
Explanation: 
The strings that can be formed are "hello" and "world" so the answer is 5 + 5 = 10.
 

Note:

1 <= words.length <= 1000
1 <= words[i].length, chars.length <= 100
All strings contain lowercase English letters only.


来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-words-that-can-be-formed-by-characters
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {

    }
};
*/



#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution1 {
public:
    int countCharacters(vector<string>& words, string chars) {
        int number = words.size(),output(0);
        int length = chars.size();
        if(number==0 || length == 0) return 0;
        
        for(size_t i=0; i<number; ++i){
            int flag =0;
            string chars1 = chars;
            for(size_t j=0; j< words[i].size(); ++j){
                for(size_t k=0; k< length; ++k){
                    if(words[i][j]== chars1[k]){
                        chars1[k]= '1';
                        flag =1;
                        break;
                    }
                    else flag = 0;
                }
                if(flag ==0)
                    break;
            }
            if(flag == 1){
                output += words[i].size();
                //cout << words[i] << endl;
            }
        }
        return output;
    }
};
/*
执行用时 :124 ms, 在所有 C++ 提交中击败了35.64%的用户
内存消耗 :18.2 MB, 在所有 C++ 提交中击败了60.32%的用户
*/



// ----- step 2 -----
class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        unordered_map<char, int> chars_cnt;
        for(char c:chars)
            ++ chars_cnt[c];
        int output = 0;
        for(string word: words){
            //! stirng word
            unordered_map<char, int> word_cnt;
            for(char c:word)
                ++ word_cnt[c];

            bool isAns = true;
            for(char c:word){
                if(chars_cnt[c] < word_cnt[c]){
                    // ? not fully understood..
                    isAns = false;
                    break;
                }
            }
            if(isAns)
                output += word.size();
        }
        return output;       
    }
};
/*
执行用时 :276 ms, 在所有 C++ 提交中击败了11.26%的用户
内存消耗 :57.5 MB, 在所有 C++ 提交中击败了5.43%的用户
*/



int main(){
    
   vector< string>  words = {"cat","bt","hat","tree"}; 
   string chars = "atach";


    Solution ans;
    cout << ans.countCharacters(words, chars) << endl;

}