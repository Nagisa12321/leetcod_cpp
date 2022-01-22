#include "leetcode.h"
#include <map>
using namespace std;

class Solution {
public:
    int eatenApples(vector<int>& apples, vector<int>& days) {
        map<int, int> m;
        int res = 0, d = 0;
        while (d < days.size() || !m.empty()) {
            if (d < days.size())
                m[d + days[d] - 1] += apples[d];    
            while (!m.empty()) {
                if (m.begin()->first < d || m.begin()->second == 0) 
                    { m.erase(m.begin()->first); }
                else {
                    --m.begin()->second;
                    res++;
                }
            }
            ++d;
        }
        return res;
    }
};