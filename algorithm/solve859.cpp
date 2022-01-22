#include "leetcode.h"
using namespace std;

class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if (s.size() != goal.size())
            return false;
        vector<int> map_s(26), map_goal(26);
        for (char c : s)
            ++map_s[c - 'a'];
        for (char c : goal)
            ++map_goal[c - 'a'];
        bool same = false;
        for (int i = 0; i < 26; ++i) {
            if (map_goal[i] != map_s[i])
                return false;
            if (map_goal[i] > 1)
                same = true;
        }
        int diff = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] != goal[i])
                ++diff;
        }
        if (diff == 2) return true;
        else if (diff == 0) return same;
        else return false;
    }
};