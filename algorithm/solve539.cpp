#include "leetcode.h"
#include <algorithm>
using namespace std;

class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        if (timePoints.size() > 1440) return 0x0;
        auto cmp = [&](const string &lhs, const string &rhs) {
            if (sub(lhs, rhs) > 0) return true;
            else return false;
        };
        sort(timePoints.begin(), timePoints.end(), cmp);
        int res = sub(timePoints[0], timePoints[1]);
        for (int i = 0; i < timePoints.size() - 1; ++i) {
            res = min(res, sub(timePoints[i], timePoints[i + 1]));
        }

        res = min(res, 24 * 60 + sub(timePoints.back(), timePoints.front()));
        return res;
    }

    int sub(const string &lhs, const string &rhs) {
        int l_hour = (lhs[0] - '0') * 10 + lhs[1] - '0';
        int l_min = (lhs[3] - '0') * 10 + lhs[4];
        int r_hour = (rhs[0] - '0') * 10 + rhs[1] - '0';
        int r_min = (rhs[3] - '0') * 10 + rhs[4]; 

        int res = (r_hour - l_hour) * 60 + r_min - l_min;
        return res;
    }
};
