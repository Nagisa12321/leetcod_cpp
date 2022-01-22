#include "leetcode.h"
using namespace std;

class Solution {
public:
    bool isAdditiveNumber(string num) {
        return helper(num, "", "", 0);
    }

    bool helper(const string &num, const string &first, const string &second, int numbers) {
        if (num.empty()) {
            if (numbers < 3)
                return false;
            else
                return true;
        }
        if (num.front() == '0') {
            if (!first.empty() && !second.empty()) {
                if (addStrings(first, second) == "0") {
                    return helper(num.substr(1), first, second, numbers + 1);
                } else
                    return false;
            } else {
                if (first.empty()) {
                    return helper(num.substr(1), "0", second, numbers + 1);
                } else {
                    return helper(num.substr(1), first, "0", numbers + 1);
                }
            }
        }

        if (!first.empty() && !second.empty()) {
            string sum_str = addStrings(first, second);
            size_t pos = num.find(sum_str);
            if (pos == string::npos)
                return false;
            string _first = second;
            string _second = sum_str;

            return helper(num.substr(pos + sum_str.size()), _first, _second, numbers + 1);
        } else {
            bool res = false;
            for (int i = 1; i < num.size(); ++i) {
                string _num = num.substr(0, i);
                if (first.empty())
                    res = res || helper(num.substr(i), _num, "", numbers + 1);
                else
                    res = res || helper(num.substr(i), first, _num, numbers + 1);
            }
            return res;
        }
    }

    string addStrings(string num1, string num2) {
        int i = num1.length() - 1, j = num2.length() - 1, add = 0;
        string ans = "";
        while (i >= 0 || j >= 0 || add != 0) {
            int x = i >= 0 ? num1[i] - '0' : 0;
            int y = j >= 0 ? num2[j] - '0' : 0;
            int result = x + y + add;
            ans.push_back('0' + result % 10);
            add = result / 10;
            i -= 1;
            j -= 1;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main() {
    Solution solve;
    bool res = solve.isAdditiveNumber("112358");
    cout << res << endl;
}
