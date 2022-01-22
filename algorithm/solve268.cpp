#include "leetcode.h"
#include <set>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int res = 0; 
        for (int i = 0; i <= nums.size(); ++i)
            res ^= i;
        for (int i : nums)
            res ^= i;
        return res;
    }
};
