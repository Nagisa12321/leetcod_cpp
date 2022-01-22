#include "leetcode.h"
using namespace std;


class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unordered_map<int, int> map;
        vector<int> res; 
        for (int i : nums)
            ++map[i];
        for (pair<int, int> entry : map) {
            if (entry.second == 1)
                res.push_back(entry.first);
        }
        return res;
    }
};