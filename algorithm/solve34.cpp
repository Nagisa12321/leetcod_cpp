#include "leetcode.h"
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int _res_left = -1, _res_right = -1;
        int lo = 0, hi = nums.size() - 1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] < target) lo = mid + 1;
            else if (nums[mid] > target) hi = mid - 1;
            else {
                if (mid == 0 || nums[mid - 1] < target) {
                    _res_left = mid;
                    break;
                } else hi = mid;
            }
        }
        lo = 0, hi = nums.size() - 1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] < target) lo = mid + 1;
            else if (nums[mid] > target) hi = mid - 1;
            else {
                if (mid == nums.size() - 1 || nums[mid + 1] > target) {
                    _res_right = mid;
                    break;
                } else lo = mid;
            }
        }
        return {_res_left, _res_right};
    }
};

int main() {
    Solution solve;
    vector<int> vec{5, 7, 7, 8, 8, 10};
    vector<int> _res = solve.searchRange(vec, 8);
    cout << "[" << _res[0] << ", " << _res[1] << "]" << endl;
}