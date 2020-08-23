/* ===========
//  * Author: Shepherd Qirong
//  * Date: 2020-03-15 16:13:45
//  * Github: https://github.com/ShepherdQR
//  * LastEditors: Shepherd Qirong
//  * LastEditTime: 2020-03-15 16:28:06
//  * Copyright (c) 2019--20xx Shepherd Qirong. All rights reserved.
*/
/*
695. Max Area of Island

Given a non-empty 2D array grid of 0's and 1's, an island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.

Find the maximum area of an island in the given 2D array. (If there is no island, the maximum area is 0.)

Example 1:

[[0,0,1,0,0,0,0,1,0,0,0,0,0],
 [0,0,0,0,0,0,0,1,1,1,0,0,0],
 [0,1,1,0,1,0,0,0,0,0,0,0,0],
 [0,1,0,0,1,1,0,0,1,0,1,0,0],
 [0,1,0,0,1,1,0,0,1,1,1,0,0],
 [0,0,0,0,0,0,0,0,0,0,1,0,0],
 [0,0,0,0,0,0,0,1,1,1,0,0,0],
 [0,0,0,0,0,0,0,1,1,0,0,0,0]]
Given the above grid, return 6. Note the answer is not 11, because the island must be connected 4-directionally.
Example 2:

[[0,0,0,0,0,0,0,0]]
Given the above grid, return 0.
Note: The length of each dimension in the given grid does not exceed 50.

通过次数26,091提交次数42,421


来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/max-area-of-island
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {

    }
};
*/

class Solution {
    public:
        int maxAreaOfIsland(vector<vector<int>>& grid) {
            int output = 0;
            for(size_t i =0; i != grid.size(); ++i){
                for(size_t j=0; j!=grid[0].size(); ++j){
                    output = max(output, dfs(grid, i,j));
                }
            }
            return output;
        }
    
    private:
        int dfs(vector<vector < int > >& grid, int cur_i, int cur_j){
            if(cur_i <0 || cur_j <0 || cur_i == grid.size() || cur_j == grid[0].size() || grid[cur_i][cur_j] != 1){
                return 0;
            }
            grid[cur_i][cur_j] = 0;
            int di[4]={0,0,1,-1};
            int dj[4]={1,-1,0,0};
            int output = 1;
            for(int index = 0; index !=4; ++index){
                int next_i = cur_i + di[index],
                next_j = cur_j + dj[index];
                output += dfs(grid, next_i, next_j);
            }
            return output;
        }
};
/*
执行用时 :12 ms, 在所有 C++ 提交中击败了95.81%的用户
内存消耗 :24.5 MB, 在所有 C++ 提交中击败了5.71%的用户

*/