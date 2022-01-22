#include <string>
#include <iostream>
#include <algorithm>
using std::cout;
using std::endl;
using std::string;

class Solution {
public:
    string addBinary(string a, string b) {
        string res = "";
        int cf = 0;
        for (int i = a.size() - 1, j = b.size() - 1; i >= 0 || j >= 0; --i, --j) {
            if (i < 0) {
                char ch = (b[j] - '0' + cf) % 2 + '0';
                cf = (b[j] - '0' + cf) / 2;
                res.push_back(ch);
            } else if (j < 0) {
                char ch = (a[i] - '0' + cf) % 2 + '0';
                cf = (a[i] - '0' + cf) / 2;
                res.push_back(ch);
            } else {
                char ch = (a[i] - '0' + b[j] - '0' + cf) % 2 + '0';
                cf = (a[i] - '0' + b[j] - '0' + cf) / 2;
                res.push_back(ch);
            }
        }
        if (cf == 1)
            res.push_back('1');

        reverse(res.begin(), res.end());
        return res;
    }
};

int main() {
    Solution solution;
    string s = solution.addBinary("1010", "1011");
    cout << s << endl;
}