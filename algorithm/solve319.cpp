#include "leetcode.h"
using namespace std;
/*
3, 5, 7, 9
*/

/*
1 - 3
2 - 5
3 - 7
*/

class Solution {
public:
    int bulbSwitch(int n) {
        int _res = 1;
        while (n > 0) {
            n -= _res++ * 2 + 1;
        }
        return _res;
    }
};

/*
2
2
2
3
3
3
3
3
4
4
4
4
4
4
4
5
5
5
5
5
5
5
5
5
6
6
6
*/