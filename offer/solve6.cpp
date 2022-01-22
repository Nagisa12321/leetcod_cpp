#include <vector>
using std::vector;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0, right = numbers.size() - 1;
        vector<int> res(2, -1);
        while (left < right) {
            int sum = numbers[left] + numbers[right];
            if (sum == target) {
                res[0] = left;
                res[1] = right;
                return res;
            } else if (sum < target) {
                left++;
            } else {
                right--;
            }
        }

        return res;
    }
};