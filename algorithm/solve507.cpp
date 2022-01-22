#include "leetcode.h"
using namespace std;

class Solution {
public:
    bool checkPerfectNumber(int num) {
        int sum = 0;
        for (int i = 1; i * 2 <= num; ++i) {
            if (num % i == 0)
                sum += i;
        }
        return sum == num;
    }
};
