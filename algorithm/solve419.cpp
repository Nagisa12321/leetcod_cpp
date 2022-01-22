#include "leetcode.h"
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int res = 0;
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                if (board[i][j] == 'X') {
                    if (i == 0 && j == 0) { ++res; }
                    else if (i == 0 && board[i][j - 1] != 'X') { ++res; } 
                    else if (j == 0 && board[i - 1][j] != 'X') { ++res; }
                    else if (i * j && board[i - 1][j] != 'X' && board[i][j - 1] != 'X') { ++res; }
                }
            }
        }
        return res;
    }
};

int main() {
    Solution solve;
    // vector<vector<char>> vec{
    //     {'X', '.', '.', 'X'},
    //     {'.', '.', '.', 'X'},
    //     {'.', '.', '.', 'X'},
    // };
    vector<vector<char>> vec{
        {'X', 'X', '.', '.'},
        {'.', '.', '.', '.'},
    };
    int res = solve.countBattleships(vec);
    cout << res; 
}