#include <vector>
#include <algorithm>
using std::vector;
using std::sort;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> tmp(3);
        if (nums.size() < 3)
            return res;
        for (int i = 0; i < nums.size() - 2; i++) {
            if (i != 0 && nums[i] == nums[i - 1])
                continue;
            int target = -nums[i];
            int left = i + 1, right = nums.size() - 1;
            while (left < right) {
                int sum = nums[left] + nums[right];
                if (sum == target) {
                    tmp[0] = nums[i];
                    tmp[1] = nums[left];
                    tmp[2] = nums[right];
                    res.push_back(tmp);
                    left++;
                    right--;

                    while (left != nums.size() - 1 && nums[left - 1] == nums[left])
                        left++;
                    while (right != 0 && nums[right + 1] == nums[right])
                        right--;
                } else if (sum < target) {
                    left++;
                } else {
                    right--;
                }
            }
        }

        return res;
    }
};

int main() {
    vector<int> vec = {-2, 0, 1, 1, 2};
    Solution solve;
    vector<vector<int>> res = solve.threeSum(vec);
}