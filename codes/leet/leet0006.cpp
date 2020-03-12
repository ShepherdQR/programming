/* ===========
//  * Author: Shepherd Qirong
//  * Date: 2020-03-12 13:46:10
//  * Github: https://github.com/ShepherdQR
//  * LastEditors: Shepherd Qirong
//  * LastEditTime: 2020-03-12 15:12:10
//  * Copyright (c) 2019--20xx Shepherd Qirong. All rights reserved.
*/

/*
1071. Greatest Common Divisor of Strings
For strings S and T, we say "T divides S" if and only if S = T + ... + T  (T concatenated with itself 1 or more times)

Return the largest string X such that X divides str1 and X divides str2.

 

Example 1:

Input: str1 = "ABCABC", str2 = "ABC"
Output: "ABC"
Example 2:

Input: str1 = "ABABAB", str2 = "ABAB"
Output: "AB"
Example 3:

Input: str1 = "LEET", str2 = "CODE"
Output: ""
 

Note:

1 <= str1.length <= 1000
1 <= str2.length <= 1000
str1[i] and str2[i] are English uppercase letters.


来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/greatest-common-divisor-of-strings
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


class Solution {
public:
    string gcdOfStrings(string str1, string str2) {

    }
};

*/

#include <iostream>
#include <string>
using namespace std;
//#include 

// step 01----
class SolutionUnfished {
public:
    string gcdOfStrings(string str1, string str2) {
        int length1 = str1.size();
        int length2 = str2.size();
        string str1add = (length2-1,"x") +str1;
        string str2add = str2+(length1-1,"x");
        string output;
        int lengthMax(0);
        

        
        for(size_t number=0; number< length1; ++number){
            int length_tmp = 0;
            string output_tmp;
            for(size_t j=0; j< number+1; ++j){
                if(str1add[length1-1-number +j]== str2add[j]){
                    length_tmp +=1;
                    output_tmp += str2add[j];
                }
                else{
                    if(length_tmp>lengthMax){
                        lengthMax = length_tmp;
                        output = output_tmp;
                    }
                    length_tmp = 0;
                    output_tmp ="";
                }
            }
        }

        int lengthOutput = output.size();
        if(lengthOutput % 2!=0)return output;
        else{
            digui(output);
        }

    }
    string digui(string & str_in){
            if(str_in.size()==1)
                return str_in;
            for(size_t i=0; i< (str_in.size()/2); ++i){
                if(str_in[i]!= str_in[i+str_in.size()/2])
                return str_in;
            }
            string strHalf(str_in, 0, str_in.size()/2-1);
            digui(strHalf);
        }
};


//a a a 2 1 0

//a a a 1 2 3
//         4 5 6 7




// step 2 no idea ... supurb
class Solution {
public:
    inline int gcd(int a, int b) {return b == 0? a : gcd(b , a % b);}
    string gcdOfStrings(string str1, string str2) {
        if (str1 + str2 != str2 + str1) return "";
        return str1.substr(0, gcd(str1.size(), str2.size()));
    }
};
/*
执行用时 :0 ms, 在所有 C++ 提交中击败了100.00%的用户
内存消耗 :8.4 MB, 在所有 C++ 提交中击败了100.00%的用户
*/



int main(){

    string a="ssss";

    //string str1 = "ABCABC", str2 = "ABC";
    string str1 = "ABABAB", str2 = "ABAB";
    Solution out;
    cout << out.gcdOfStrings(str1, str2) << endl;
    return 0;
}