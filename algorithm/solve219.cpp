#include "leetcode.h"
#include <set>
using namespace std; 

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        set<int> s;
        if (k >= nums.size()) {
            for (int i = 0; i < nums.size(); ++i) {
                if (s.count(nums[i])) return true;
                s.insert(nums[i]);
            }
            return false;
        } else {
            for (int i = 0; i < k; ++i) {
                if (s.count(nums[i])) return true;
                s.insert(nums[i]);
            }
            for (int i = 0; i < nums.size() - k; ++i) {
                if (s.count(nums[i + k]))
                    return true;
                s.insert(nums[i + k]);
                s.erase(nums[i]);
            }
            return false;
        }
    }
};
