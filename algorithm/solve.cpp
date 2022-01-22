#include <iostream>

using namespace std;

class Solution {
public:
    int countSegments(string s) {
        if (s.empty()) return 0;
        int res = 0, st = 0;
        for (char ch : s) {
            if (ch == ' ') {
                if (!st) continue;
                if (st == 1) ++res;
                st = 2;
            } else st = 1;
        }
        return s[s.size() - 1] == ' ' ? res : res + 1;
    }
};