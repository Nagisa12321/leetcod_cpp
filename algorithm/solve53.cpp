// io
#include <iostream>
#include <cstdlib>
#include <cstdio>

// containers
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <vector>
#include <forward_list>

// algorithm
#include <algorithm>
#include <numeric>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        size_t sz = nums.size();
        vector<int> dp(sz);
        int _res = nums[0];
        dp[0] = nums[0];
        for (int i = 1; i < sz; ++i) {
            dp[i] = max(nums[i], dp[i - 1] + nums[i]);
            _res = max(dp[i], _res);
        }
        return _res;
    }
};