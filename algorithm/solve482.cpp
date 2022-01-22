#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>
#include <list>
#include <vector>
#include <forward_list>

using namespace std;

class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        vector<char> vec;
        for (char c : s) 
            if (c != '-')
                vec.push_back(c);

        int one = vec.size() % k;
        if (!one) one = k;

        string res;
        for (int i = 0; i < one; ++i)
            res.push_back(toupper(vec[i]));
        res.push_back('-');

        int num = 0;
        for (int i = one; i < vec.size(); ++i) {
            res.push_back(toupper(vec[i]));
            num++;
            if (num == k) {
                num = 0;
                res.push_back('-');
            }
        }

        if (res.back() == '-')
            res.pop_back();

        return res;
    }
};