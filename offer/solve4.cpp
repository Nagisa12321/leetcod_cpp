#include <vector>

using std::vector;

class Solution {
public:
    int singleNumber(vector<int> &nums) {
        int res = 0;
        for (int i = 0; i < 32; i++) {
            int tmp = 0;
            for (int j = 0; j < nums.size(); j++) {
                if ((nums[j] >> i) & 1)
                    tmp++;
            }
            res += (tmp % 3) << i;
        }

        return res;
    }
};