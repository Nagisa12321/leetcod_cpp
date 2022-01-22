#include "leetcode.h"

using namespace std;

class Solution {
public:
    bool reorderedPowerOf2(int n) {
        vector<int> twices{1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536, 131072, 262144, 524288, 1048576, 2097152, 4194304, 8388608, 16777216, 33554432, 67108864, 134217728, 268435456, 536870912, 1073741824};
        unordered_map<int, int> nums;
        int sz = 0;
        while (n) {
            ++nums[n % 10];
            n /= 10;
            ++sz;
        }
        for (int twice : twices) {
            string s = to_string(twice);
            if (s.size() == sz) {
                bool _continue = false;
                unordered_map<int, int> _nums(nums);
                for (char c : s) 
                    if (!_nums.count(c - '0')) {
                        _continue = true;
                        break;
                    } else {
                        --_nums[c - '0'];
                        if (!_nums[c - '0'])
                            _nums.erase(c - '0');
                    }
                if (_continue) continue;
                else return true;
            }
        }

        return false;
    }
};

int main() {
    Solution solve;
    bool res = solve.reorderedPowerOf2(268341);
    cout << res << endl;
}