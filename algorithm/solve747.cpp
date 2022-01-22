#include "leetcode.h"
using namespace std;

class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int max = nums[0];
        int max_idx = 0;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] > max) {
                max = nums[i];
                max_idx = i;
            }
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (i != max_idx) {
                if ((nums[i] << 1) > max)
                   return -1; 
            }
        }
        return max_idx;
    }
};
