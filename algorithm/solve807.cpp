#include "leetcode.h"
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int __len_i = grid.size();
        int __len_j = grid[0].size(); 
        vector<int> __i_max(__len_i); 
        vector<int> __j_max(__len_j);
        for (int __i = 0; __i < __len_i; ++__i) {
            for (int __j = 0; __j < __len_j; ++__j) {
                __i_max[__i] = max(__i_max[__i], grid[__i][__j]);
                __j_max[__j] = max(__j_max[__j], grid[__i][__j]);
            }
        }
        int __res = 0;
        for (int __i = 0; __i < __len_i; ++__i) {
            for (int __j = 0; __j < __len_j; ++__j) {
                __res += min(__i_max[__i], __j_max[__j]) - grid[__i][__j];
            }
        }
        return __res;
    }
};