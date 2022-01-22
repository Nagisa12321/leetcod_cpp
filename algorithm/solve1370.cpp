// io
#include <iostream>
#include <cstdlib>
#include <cstdio>

// containers
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <vector>
#include <forward_list>

// algorithm
#include <algorithm>
#include <numeric>

using namespace std;

class Solution {
public:
    string sortString(string s) {
        int map[26] = { 0 };
        for (char c : s)
            map[c - 'a']++;
        int idx = 0, d = 1, sz = s.size(), r = sz;
        string res;
        while (true) {
            if (idx == 26) {
                d = 0;
                --idx;
            } else if (idx == -1) {
                d = 1;
                ++idx;
            }
            
            if (map[idx]) {
                --map[idx];
                res.push_back(idx + 'a');
                --r;
            }
            if (!r)
                break;
            
            if (d) ++idx;
            else --idx;
        }

        return res;
    }
};

int main() {
    Solution sl;
    string s = sl.sortString("rat");
    cout << s << endl;
}