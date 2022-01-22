#include "leetcode.h"
using namespace std;

class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map<int, int> map;
        int _res = 0; 
        for (int i : arr) {
            map[i] = max(1, map[i - difference] + 1);
            _res = max(map[i], _res);
        }
        return _res;
    }
};