#include "leetcode.h"
using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if (s.size() < p.size()) return vector<int>();
        int p_map[26] = { 0 };
        int s_map[26] = { 0 };
        int sz = s.size(), psz = p.size();
        for (int i = 0; i < psz; ++i) {
            ++s_map[s[i] - 'a'];
            ++p_map[p[i] - 'a'];
        }
        int l = 0, r = l + psz;
        vector<int> res;
        while (1) {
            if (map_equals(s_map, p_map))
                res.push_back(l);
            if (r == sz)
                break;
            --s_map[s[l++] - 'a'];
            ++s_map[s[r++] - 'a'];
        }
        return res;
    }

    bool map_equals(int *a, int *b) {
        for (int i = 0; i < 26; ++i)
            if (a[i] != b[i])
                return false;
        return true;
    }
};