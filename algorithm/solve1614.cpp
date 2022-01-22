#include "leetcode.h"
using namespace std;

class Solution {
public:
    int maxDepth(string s) {
        int res = 0, deep = 0;
        for (char c : s) {
            if (c == '(') ++deep;
            if (c == ')') --deep;
            res = max(res, deep);
        }
        return res;
    }
};
