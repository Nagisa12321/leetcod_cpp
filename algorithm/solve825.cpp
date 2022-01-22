#include "leetcode.h"
using namespace std;

class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        sort(ages.begin(), ages.end());
        int res = 0; 
        for (int i = 0, j = 0, k = 0; k < ages.size(); ++k) {
            while (i < k && !fix(ages, i, k)) ++i;
            if (j < k) j = k;
            while (j < ages.size() && fix(ages, j, k)) ++j;
            if (j > i) res += j - i + 1; 
        }
        return res;
    }

    bool fix(vector<int> &ages, int x, int y) {
        if (ages[y] <= 0.5 * ages[x] + 7 || ages[y] > ages[x] || (ages[y] > 100 && ages[x] < 100))
            return false;
        return true;
    }
};