#include "leetcode.h"
#include <deque>
using namespace std;

class Solution {
public:
    Solution(int m, int n)
        : n(n),
          m(m)
    {

    }
    
    vector<int> flip() {
        while (1) {
            int pos = rand() % (n * m);
            if (exists.count(pos)) 
                continue;
            exists.insert(pos);
            int x = pos / n;
            int y = pos % n;
            return {x, y};
        }
    }
    
    void reset() {
        exists.clear();
    }

private:
    unordered_set<int> exists;
    int n, m;
};