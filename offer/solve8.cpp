#include <vector>
#include <algorithm>

using std::min;
using std::vector;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum = nums[0], left = 0, right = 0;
        int res = nums.size() + 1;
        while (1) {
            if (sum >= target) {
                if (left == right)
                    return 1;
                else {
                    res = min(right - left + 1, res);
                    sum -= nums[left++];
                }
            } else {
                if (right == nums.size() - 1)
                    break;
                sum += nums[++right];
            }
        }
        return res == nums.size() + 1 ? 0 : res;
    }
};