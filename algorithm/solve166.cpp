#include <iostream>
#include <map>

using namespace std;

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        string res;
        string tmp;

        long long n = numerator, d = denominator;
        if ((double)n / d < 0)
            tmp.push_back('-');
        n = abs(n); d = abs(d);
        tmp += to_string(n / d);
        long long num = (n % d) * 10;
        if (!num) return tmp;
        tmp.push_back('.');
        map<long long, int> m;
        bool reverse = false;
        while (num) {
            if (m.count(num)) {
                reverse = true;
                res.insert(m[num], 1, '(');
                break;
            }
            m[num] = res.size();
            res.push_back((num / d) + '0');
            num = (num % d) * 10;
        }
        if (reverse) res.push_back(')');
        return tmp + res;
    }
};

int main() {
    Solution s;
    string res = s.fractionToDecimal(-50, 8);
    cout << res << endl;
}