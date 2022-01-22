#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        bool per = false;
        if ((dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0))
            per = true;
        
        long long r = divide_unsigned(abs(dividend), abs(divisor));
        long long res = per ? -r : r;
        if (res > 0) res = min(res, (long long)INT32_MAX);
        if (res < 0) res = max(res, (long long)INT32_MIN);
        return res;
    }

    long long divide_unsigned(long long dividend, long long divisor) {
        if (dividend < divisor)
            return 0;
        long long tmp = divisor;
        int res = 1;
        while (dividend >= divisor) {
            divisor <<= 1;
            res <<= 1;
        }
        while (dividend < divisor) {
            divisor -= tmp;
            res -= 1;
        }
        return res;
    }
};

int main() {
    Solution sol;
    int res = sol.divide(-2147483648, -1);
    cout << res << endl;
}