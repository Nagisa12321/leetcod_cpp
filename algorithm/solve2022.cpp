#include "leetcode.h"

using namespace std; 

class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        if (m * n != original.size()) 
            return vector<vector<int>>();
        
        int idx = 0;
        vector<vector<int>> res(m, vector<int>(n));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                res[i][j] = original[idx++]; 
            }
        }
        return res;
    }
};

