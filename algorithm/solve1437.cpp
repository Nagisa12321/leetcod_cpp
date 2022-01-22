#include "leetcode.h"
using namespace std;

class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int idx = -1;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == 1) {
                if (idx != -1) {
                    if (i - idx - 1 < k)
                        return false;
                }
                idx = i;
            }
        }
        return true;
    }
};

int main() {
    Solution solve;
    vector<int> ivec{1, 0, 0, 1, 0, 1};
    bool res = solve.kLengthApart(ivec, 2);
    cout << res << endl;
}