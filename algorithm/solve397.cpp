#include "leetcode.h"
using namespace std;

class Solution {
public:
    unordered_map<int, int> m;
    int integerReplacement(int n) {
        if (n == 1) return 0;
        if (m.count(n)) return m[n];
        int res;
        if (n % 2) {
            int _res1 = integerReplacement(n - 1);
            int _res2;
            if (n == 2147483647) 
                _res2 = 2147483647;
            else 
                _res2 = integerReplacement(n + 1);
            res = min(_res1, _res2);
        } else {
            res = integerReplacement(n >> 1);
        }     
        m[n] = res + 1;
        return res + 1;
    }
};

int main() {
    cout << (0xffffffff >> 1) << endl;
    cout << 2147483647 << endl;
    cout << INT32_MAX << endl;
}