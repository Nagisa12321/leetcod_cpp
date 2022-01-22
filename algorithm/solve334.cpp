#include "leetcode.h"
using namespace std;

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int first = INT32_MAX;
        int second = INT32_MAX;
        for (int i : nums) {
            if (i < first) first = i;
            else if (i < second) second = i;
            else return true;
        }
        return false;
    }
};
