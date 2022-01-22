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
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char> set;
        for (int i = 0; i < 9; ++i) {
            set.clear();
            for (int j = 0; j < 9; ++j) {
                char ch = board[i][j];
                if (ch == '.')
                    continue;
                else if (set.count(ch))    
                    return false;
                else 
                    set.insert(ch);
            }
        }
        for (int i = 0; i < 9; ++i) {
            set.clear();
            for (int j = 0; j < 9; ++j) {
                char ch = board[j][i];
                if (ch == '.')
                    continue;
                else if (set.count(ch))    
                    return false;
                else 
                    set.insert(ch);
            }
        }
        for (int i = 0; i < 9; i += 3) {
            for (int j = 0; j < 9; j += 3) {
                set.clear();
                for (int x = 0; x < 3; ++x) {
                    for (int y = 0; y < 3; ++y) {
                        char ch = board[i + x][j + y];
                        if (ch == '.')
                            continue;
                        else if (set.count(ch))    
                            return false;
                        else 
                            set.insert(ch);
                    } 
                }
            }
        }
        return true;
    }
};