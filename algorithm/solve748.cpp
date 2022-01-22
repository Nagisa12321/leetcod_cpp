#include "leetcode.h"
#include <cctype>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        vector<int> __map(26);
        for (char __c : licensePlate) {
            if (isalpha(__c)) {
                ++__map[tolower(__c) - 'a'];
            }
        }

        int __min = 0xfffff;
        string __res;
        for (string &__s : words) {
            vector<int> __tmp(26);
            for (char __c : __s) { 
                ++__tmp[__c - 'a']; 
            }

            bool __is_word = true;
            for (int __offset = 0; __offset < 26; ++__offset) {
                if (__tmp[__offset] < __map[__offset]) {
                    __is_word = false;
                    break;
                }
            }

            if (__is_word) {
                if (__s.size() < __min) {
                    __res = __s;
                    __min = __s.size();
                }
            }
        }

        return __res;
    }
};

int main() {
    Solution __solve;
    vector<string> __svec{"step", "steps", "stripe", "stepple"};
    string __res = __solve.shortestCompletingWord("1s3 PSt", __svec);
    cout << __res << endl;
}