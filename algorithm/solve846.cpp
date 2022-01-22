#include "leetcode.h"
using namespace std;

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        sort(hand.begin(), hand.end());
        map<int, int> m;
        for (int i : hand) {
            ++m[i];
        }
        while (!m.empty()) {
            int tmp = m.begin()->first;
            m.begin()->second--;
            if (!m.begin()->second)
                m.erase(m.begin());
            for (int i = 1; i < groupSize; ++i) {
                if (!m.count(tmp + i))
                    return false;
                else --m[tmp + i];
                if (!m[tmp + i])
                    m.erase(tmp + i);
            }
        }
        return true; 
    }
};
