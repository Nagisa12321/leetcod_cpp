#include "leetcode.h"
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int __len_i = matrix.size(), __len_j = matrix[0].size();
        vector<vector<int>> __dp(__len_i, vector<int>(__len_j));
        int __res = 0;
        for (int i = 0; i < __len_i; ++i) {
            for (int j = 0; j < __len_j; ++j) {
                if (matrix[i][j] == '1') {
                    if (i == 0 || j == 0) {
                        __dp[i][j] = 1;
                    } else {
                        __dp[i][j] = min(__dp[i - 1][j],
                                         __dp[i][j - 1],
                                         __dp[i - 1][j - 1]) + 1;
                    }
                } else {
                    __dp[i][j] = 0;
                }
                __res = max(__res, __dp[i][j]);
            }
        }
        return __res * __res;
    }

    int min(int i, int j, int k) {
        return std::min(std::min(i, j), k);
    } 
};
