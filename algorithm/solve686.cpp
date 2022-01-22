#include "leetcode.h"
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        int __limit = 2 * a.size() + b.size();
        int __helper = __limit / a.size();
        if (__limit % a.size()) ++__helper;
        string __a;
        for (int i = 1; i <= __helper; ++i) {
            __a += a;
            if (strStr(__a, b) != -1)
                return i;
        }
        return -1;
    }

    int strStr(string haystack, string needle) {
        int n = haystack.size(), m = needle.size();
        if (m == 0) {
            return 0;
        }
        vector<int> pi(m);
        for (int i = 1, j = 0; i < m; i++) {
            while (j > 0 && needle[i] != needle[j]) {
                j = pi[j - 1];
            }
            if (needle[i] == needle[j]) {
                j++;
            }
            pi[i] = j;
        }
        for (int i = 0, j = 0; i < n; i++) {
            while (j > 0 && haystack[i] != needle[j]) {
                j = pi[j - 1];
            }
            if (haystack[i] == needle[j]) {
                j++;
            }
            if (j == m) {
                return i - m + 1;
            }
        }
        return -1;
    }
};

int main() {
    Solution solve;
    string a = "abcd";
    string b = "cdabcdab";
    int res = solve.repeatedStringMatch(a, b);
    cout << res;
}