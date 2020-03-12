/* ===========
//  * Author: Shepherd Qirong
//  * Date: 2020-03-10 21:41:28
//  * Github: https://github.com/ShepherdQR
//  * LastEditors: Shepherd Qirong
//  * LastEditTime: 2020-03-10 23:09:52
//  * Copyright (c) 2019--20xx Shepherd Qirong. All rights reserved.
*/
/* ===========
//  * Author: Shepherd Qirong
//  * Date: 2020-03-10 21:41:28
//  * Github: https://github.com/ShepherdQR
//  * LastEditors: Shepherd Qirong
//  * LastEditTime: 2020-03-10 21:55:32
//  * Copyright (c) 2019--20xx Shepherd Qirong. All rights reserved.
*/
/* ===========
//  * Author: Shepherd Qirong
//  * Date: 2020-03-10 21:41:28
//  * Github: https://github.com/ShepherdQR
//  * LastEditors: Shepherd Qirong
//  * LastEditTime: 2020-03-10 21:54:08
//  * Copyright (c) 2019--20xx Shepherd Qirong. All rights reserved.
*/

/*
543. Diameter of Binary Tree

Given a binary tree, you need to compute the length of the diameter of the tree. The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.

Example:
Given a binary tree 
          1
         / \
        2   3
       / \     
      4   5    
Return 3, which is the length of the path [4,2,1,3] or [5,2,1,3].

Note: The length of path between two nodes is represented by the number of edges between them.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/diameter-of-binary-tree
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


// *
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
//  * };
//  
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {

    }
};
*/
//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};



// step 1 ===== wrong  
class Solution1 {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL) return 0;

        int length = 0;
        TreeNode * current = root;
        while(current->left != NULL){
            length +=1;
            current = current->left;
        }
        current = root;
        while(current->right != NULL){
            length +=1;
            current = current->right;
        }
        return length;
    }
};
// 3, 1 null, null ,2




class Solution{
    private:
        int output = 0;
    public:
        int diameterOfBinaryTree(TreeNode* root) {
            recursiveF(root);
            return output;
        }
    private:
        int recursiveF(TreeNode * root){
            if(root == NULL) return 0;
            int leftHeight = recursiveF(root->left);
            int rightHeight = recursiveF(root->right);
            output = max(output, leftHeight + rightHeight);
            return max(leftHeight, rightHeight)+1;
        }
};// actually not quite understood.
/*
16ms, 59.15%;
22.6MB, 15.48%
*/