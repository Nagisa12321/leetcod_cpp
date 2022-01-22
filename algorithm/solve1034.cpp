#include "leetcode.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        vector<vector<int>> res(grid.begin(), grid.end());
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        if (colorBorder(visited, res, grid, row, col, grid[row][col], color))
            res[row][col] = color;
        return res;
    }
    
    /* return true means the caller is the limit */
    bool colorBorder(vector<vector<bool>> &visited,
                     vector<vector<int>> &res, 
                     vector<vector<int>> &grid, 
                     int row, 
                     int col,
                     int old_color,
                     int new_color) {
        if (row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size())
            return true;
        else if (grid[row][col] != old_color)
            return true;
        else if (visited[row][col])
            return false;
        visited[row][col] = true;
        
        bool is_limit = false;
        is_limit |= colorBorder(visited, res, grid, row + 1, col, old_color, new_color);
        is_limit |= colorBorder(visited, res, grid, row - 1, col, old_color, new_color);
        is_limit |= colorBorder(visited, res, grid, row, col + 1, old_color, new_color);
        is_limit |= colorBorder(visited, res, grid, row, col - 1, old_color, new_color);
        if (is_limit)
            res[row][col] = new_color;
        return true;
    }
};