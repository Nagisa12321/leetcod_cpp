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
    int longestPalindrome(string s) {
        int map[256] = { 0 };
        for (char c : s)
            map[c]++;
        int res = 0, si = 0;
        for (int i : map) 
            if (i % 2) {
                res += i - 1;
                si = 1;
            } else {
                res += i;
            }
        return res + si;
    }
};