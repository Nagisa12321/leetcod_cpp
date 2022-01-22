#include <vector>
using std::vector;

class Solution {
public:
    int countBits_helper(int n) {
        n = (n & 0x55555555) + ((n >> 1) & 0x55555555);
        n = (n & 0x33333333) + ((n >> 2) & 0x33333333);
        n = (n & 0x0f0f0f0f) + ((n >> 4) & 0x0f0f0f0f);
        n = (n & 0x00ff00ff) + ((n >> 8) & 0x00ff00ff);
        n = (n & 0x0000ffff) + ((n >> 16) & 0x0000ffff);
        return n;
    }

    vector<int> countBits(int n) {
        vector<int> v;
        for (int i = 0; i <= n; i++) {
            v.push_back(countBits_helper(i));
        }

        return v;
    }
};