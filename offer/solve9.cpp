#include <vector>
#include <iostream>

using std::cout;
using std::endl;
using std::vector;

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int mul = 1;
        int len = nums.size();
        int left = 0, res = 0;
        for (int right = 0; right < len; ++right) {
            mul *= nums[right];
            while (left <= right && mul >= k) 
                mul /= nums[left++];
            
            if (left <= right)
                res += right - left + 1;
        }
        
        return res;
    }
};

int main() {
    Solution solution;
    vector<int> v = {10, 5, 2, 6};
    int res = solution.numSubarrayProductLessThanK(v, 100);
    cout << res << endl;
}