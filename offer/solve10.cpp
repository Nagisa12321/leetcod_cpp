#include <iostream>
#include <vector>
#include <map>

using std::cout;
using std::vector;
using std::map;
using std::endl;

class Solution {
public:
    int subarraySum(vector<int> &nums, int k) {
        size_t sz = nums.size();

        // maps[i][j] -> ending of index i
        // and the sum is k's number
        vector<map<int, int>> maps(sz);

        maps[0][nums[0]] = 1;
        for (size_t i = 1; i < sz; ++i) {
            maps[i] = maps[i - 1];
            for (auto it = maps[i - 1].rbegin(); it != maps[i - 1].rend(); ++it) {
                maps[i][it->first + nums[i]] += 1;
            }
            maps[i][nums[i]] += 1;
        }

        return maps[sz - 1][k];
    }
};

int main() {
    Solution solve;

    vector<int> v = {1, 1, 1};
    int res = solve.subarraySum(v, 2);
    cout << res << endl;
}