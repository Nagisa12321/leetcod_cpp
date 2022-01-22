#include <iostream>
#include <cstdio>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <vector>
#include <forward_list>

using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        if (n == 1)
            return "1";
        
        string prev = countAndSay(n - 1);
        
        string res;
        char ch = 0;
        int num = 0;
        for (char c : prev) {
            if (c != ch) {
                if (ch != 0) {
                    res += to_string(num);
                    res.push_back(ch);
                }
                ch = c;
                num = 1;
            } else {
                ++num;
            }
        }
        if (num != 0) {
            res += to_string(num);
            res.push_back(ch);
        }

        return res;
    }
};

int main() {
    Solution solve;
    string s = solve.countAndSay(2);
    cout << s << endl;
}