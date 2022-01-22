#include "leetcode.h"
using namespace std;

class Solution {
public:
    int lastRemaining(int n) {
        if (n <= 2) return 1;
        return 2 * (n + 1 - lastRemaining(n >> 1));
    }
};
