// io
#include <iostream>
#include <cstdio>

// containers
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <vector>
#include <forward_list>

// algorithm
#include <algorithm>
#include <numeric>

using namespace std;

constexpr int INF = 0xffffcccc;
class Solution {
public:
    vector<string> addOperators(string num, int target) {
        vector<string> res;
        addOperators(num, target, "", res);
        return res;
    }

    int string_to_int(string s) {
        if (s[0] == '0' && s.size() != 1)
            return INF;
        int res;
        try {
            res = stoi(s);
        } catch (std::out_of_range r) {
            return INF;
        }
        return res;
    }

    void addOperators(const string &num, int target, const string &expr, vector<string> &res) {
        if (string_to_int(num) == abs(target)) {
            if (expr.empty())
                res.push_back(to_string(target));
            else {
                if (target == 0) {
                    res.push_back(expr + "+0");
                    res.push_back(expr + "-0");
                } else if (target > 0)
                    res.push_back(expr + "+" + to_string(target));
                else
                    res.push_back(expr + to_string(target));
            }
        }
        if (num.empty()) return;
        for (int i = 1; i < num.size(); ++i) {
            string left = num.substr(0, i);
            string right = num.substr(i);

            int left_int = string_to_int(left);
            if (left_int == INF)
                break;
            addOperators(right, target - left_int,
                         expr + (expr.empty() ? to_string(left_int) : "+" + to_string(left_int)),
                         res);
            if (!expr.empty())
                addOperators(right, target + left_int, expr + "-" + to_string(left_int), res);

            vector<pair<string, int>> mul = multi(left);
            for (pair<string, int> p : mul) {
                addOperators(right, target - p.second,
                             expr + (expr.empty() ? p.first : "+" + p.first),
                             res);
                if (!expr.empty())
                    addOperators(right, target + p.second, expr + "-" + p.first, res);
            }
        }
    }

    vector<pair<string, int>> multi(const string &num) {
        vector<pair<string, int>> res;

        for (int i = 1; i < num.size(); ++i) {
            string left = num.substr(0, i);
            string right = num.substr(i);

            int left_int = string_to_int(left);
            int right_int = string_to_int(right);
            if (left_int == INF || right_int == INF)
                break;

            res.push_back({left + "*" + right,
                           left_int * right_int});
        }

        return res;
    }
};

int main() {
    Solution solve;
    vector<string> res = solve.addOperators("123", 6);
    for (const string &s : res)
        cout << s << endl;
}