// io
#include <iostream>
#include <sstream>
#include <fstream>
#include <cstdlib>
#include <cstdio>

// containers
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <vector>
#include <forward_list>

// algorithm
#include <algorithm>
#include <iterator>
#include <numeric>

// memory
#include <memory>

using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>> &board, string word) {
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                if (exist(board, word, i, j, 0))
                    return true;
            }
        }
        return false;
    }

private:
    bool exist(vector<vector<char>> &board, string word, int i, int j, int idx) {
        if (idx == word.size())
            return true;
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size())
            return false;
        if (word[idx] != board[i][j])
            return false;

        char tmp = board[i][j];
        board[i][j] = '\0';

        if (exist(board, word, i + 1, j, idx + 1)) goto ret;
        if (exist(board, word, i - 1, j, idx + 1)) goto ret;
        if (exist(board, word, i, j + 1, idx + 1)) goto ret;
        if (exist(board, word, i, j - 1, idx + 1)) goto ret;
        
        board[i][j] = tmp;
        return false;
    ret:
        board[i][j] = tmp;
        return true;
    }
};