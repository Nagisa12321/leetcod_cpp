#include "leetcode.h"
using namespace std;

class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        unordered_map<int, int> m1;
        for (int i : candyType)
            ++m1[i];

        int get = candyType.size() / 2;
        if (m1.size() >= get) return get;
        else return m1.size();
    }
};