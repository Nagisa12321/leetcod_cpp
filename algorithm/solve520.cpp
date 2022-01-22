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
    bool detectCapitalUse(string word) {
        int first = 0, up = 0, down = 0;
        for (int i = 0; i < word.size(); ++i) {
            if (!i) first = isupper(word[0]);

            if (isupper(word[i])) ++up;
            else ++down;
        }

        if (first)
            return !down || up == 1;
        else
            return !up && down;
    }
};