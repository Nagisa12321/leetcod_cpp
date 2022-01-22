#include "leetcode.h"
#include <unordered_set>
using namespace std; 

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res;  
        unordered_set<int> set;
        tracker(0, n, set, res);
        return res;
    }

    void tracker(int a, unsigned int n, unordered_set<int> &set, vector<int> &res) {
        res.push_back(a);
        set.insert(a);
        for (int i = 0; i < n; ++i) {
            int bit = (a & (1 << i)) >> i;
            int na;
            if (bit == 0) na = a | (1 << i);
            if (bit == 1) na = a & (~(1 << i));
            
            if (!set.count(na)) {
                tracker(na, n, set, res);
                break;
            }
        }
    }
};


int main() {
    Solution solve;
    vector<int> res = solve.grayCode(3);
    for (int i = 0; i < res.size(); ++i) {
        cout << res[i] << " ";
    }
    cout << endl;
}
