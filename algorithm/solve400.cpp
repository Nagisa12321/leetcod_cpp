#include "leetcode.h"
#include <cmath>
using namespace std;

class Solution {
public:
    int findNthDigit(int n) {
        int a = 9, b = 1;
        while (n > a * b) {
            n -= a * b;
            a *= 10;
            b += 1;
        }
        int c = (n + b - 1) / b;
        int le = (n - 1) % b;
        int base = pow(10, b - 1);
        int num = base + c - 1;
        int ri = b - le - 1;
        return num / (int) pow(10, ri) % 10;
    }
};  

int main() {
    Solution solve;
    int res = solve.findNthDigit(100);
    cout << res << endl;
}