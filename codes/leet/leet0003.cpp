/* ===========
//  * Author: Shepherd Qirong
//  * Date: 2020-03-09 21:13:57
//  * Github: https://github.com/ShepherdQR
//  * LastEditors: Shepherd Qirong
//  * LastEditTime: 2020-03-09 21:35:10
//  * Copyright (c) 2019--20xx Shepherd Qirong. All rights reserved.
*/

/*
206. Reverse Linked List
Reverse a singly linked list.

Example:

Input: 1->2->3->4->5->NULL
Output: 5->4->3->2->1->NULL
Follow up:

A linked list can be reversed either iteratively or recursively. Could you implement both?

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/reverse-linked-list
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

// 
//  * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     ListNode *next;
//  *     ListNode(int x) : val(x), next(NULL) {}
//  * };
//  
class Solution {
public:
    ListNode* reverseList(ListNode* head) {

    }
};

*/
//=========================
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


// step 1 ==== cannot figure out myself, so this method is learned.
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head==NULL )
            return head;
        ListNode * priview = NULL;
        ListNode * current = head;
        while (current != NULL){
            // also can write like 
            // while(current){...}, runs may slowly
            ListNode * temp = current->next;
            current->next = priview;
            priview = current;
            current = temp;
        }
        return priview;
    }
};
/*
执行用时 :4 ms, 在所有 C++ 提交中击败了96.76%的用户
内存消耗 :9.5 MB, 在所有 C++ 提交中击败了5.19%的用户
*/



