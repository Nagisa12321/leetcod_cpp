#include "leetcode.h"
using namespace std;

bool str_cmp(const string &s1, const string &s2) {
    if (s1.size() != s2.size())
        return s1.size() > s2.size();
    else 
        return s1 > s2;
}

class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        set<string, decltype(str_cmp) *> all(str_cmp);
        remove_helper(all, "", s, 0);

        vector<string> legitimate;
        int max = 0;
        for (const string &s : all) {
            if (is_legitimate(s)) {
                max = s.size();
                break;
            }
        }

        for (const string &s : all) {
            if (s.size() == max && is_legitimate(s))
                legitimate.push_back(s);
        }

        return legitimate;
    }

    void remove_helper(set<string, decltype(str_cmp) *> &all, string cur, string s, int idx) {
        if (idx == s.size()) {
            all.insert(cur);
            return;
        }

        // delete
        remove_helper(all, cur, s, idx + 1);

        // not delete
        cur.push_back(s[idx]);
        remove_helper(all, cur, s, idx + 1);
    }
 
    bool is_legitimate(const string &s) {
        vector<char> stack;
        for (char c : s) {
            if (c == ')') {
                while (!stack.empty() && stack.back() != '(' && stack.back() != ')')
                    stack.pop_back();
                if (stack.empty())
                    return false;
                if (stack.back() == '(')
                    stack.pop_back();
            } else 
                stack.push_back(c);
        }

        for (char c : stack) 
            if (c == '(')
                return false;
        
        return true;
    }
};

int main() {
    string s = "i))((()(n(())i((((";
    Solution solve;
    vector<string> res = solve.removeInvalidParentheses(s);
    for (const string &s : res) 
        cout << s << endl;
}