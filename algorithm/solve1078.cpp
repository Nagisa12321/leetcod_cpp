#include "leetcode.h"
#include <sstream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {
        istringstream iss(text);
        string word, tmp1, tmp2;
        vector<string> res;
        while (iss >> word) {
            if (tmp1 == second && tmp2 == first)
                res.push_back(word);
            tmp2 = tmp1;
            tmp1 = word;
        }
        return res;
    }
};