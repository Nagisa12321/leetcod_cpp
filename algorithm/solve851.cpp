#include "leetcode.h"
#include <algorithm>
#include <map>
#include <vector>
#include <functional>
using namespace std;

class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& __quiet) {
        int __n = __quiet.size();
        vector<vector<int>> __graph(__n);
        for (const vector<int> __vec : richer) {
            __graph[__vec[1]].push_back(__vec[0]);
        }
        vector<int> __res(__n, -1); 

        function<void(int)> __dfs = [&](int __idx) {
            if (__res[__idx] == -1 ||__quiet[__idx] < __quiet[__min_idx]) { __min_idx = __idx; }
            for (int __next_idx : __graph[__idx]) {
                __dfs(__next_idx);
            }
        };
        
        for (int __offset = 0; __offset < __n; ++__offset) {
            __dfs(__offset);
        }
        return __res;
    }
};
int main() {
    vector<vector<int>> __richer{
        {1, 0}, {2, 1}, {3, 1}, {3, 7}, {4, 3}, {5, 3}, {6, 3}
    };
    vector<int> __quiet{3, 2, 4, 5, 6, 1, 7, 0};
    Solution solve;
    vector<int> __res = solve.loudAndRich(__richer, __quiet);
    for (int i : __res)
        cout << i << " ";
}