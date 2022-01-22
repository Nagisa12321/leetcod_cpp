#include "leetcode.h"
#include <string>

using namespace std;

class Solution {
public:
    string truncateSentence(string __s, int __k) {
        int __idx = 0, __space = 0;
        while (__space < __k) {
            if (__idx == __s.size()) { __idx++; break; }
            if (__s[__idx++] == ' ') { __space++; }
        } 
        return string(__s.begin(), __s.begin() + __idx - 1);
    }
};