#include "leetcode.h"
using namespace std;

/*
z   
e   1
r   
o   1, 2
n   1
t   2
w   2
h   
f   
u   
i   
v   
s   
x  
g   

8(g) -> 6(x) -> 7(s) -> 0(z) -> 5(v) -> 4(u) -> 9(i) -> 3(h) -> 1(n) -> 2(w)
*/
class Solution {
public:
    int nums_map[10][26] = {
        {0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, }, 
        {0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, }, 
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, }, 
        {0, 0, 0, 0, 2, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, }, 
        {0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, }, 
        {0, 0, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, }, 
        {0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, }, 
        {0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, }, 
        {0, 0, 0, 0, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, }, 
        {0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, }, 
    };

    pair<int, char> pairs[10] = {
        {8, 'g'}, {6, 'x'}, {7, 's'}, {0, 'z'}, {5, 'v'},
        {4, 'u'}, {9, 'i'}, {3, 'h'}, {1, 'n'}, {2, 'w'},
    };
    string originalDigits(string s) {
        int map[26] = { 0 };
        for (char c : s) ++map[c - 'a'];
        vector<int> res;
        for (int i = 0; i < 10; ++i) {
            int times = map[pairs[i].second - 'a'];
            for (int j = 0; j < times; ++j) {
                for (int k = 0; k < 26; ++k) {
                    map[k] -= nums_map[pairs[i].first][k];
                }
                res.push_back(pairs[i].first);
            }
        }   
        sort(res.begin(), res.end());
        string _res;
        for (int i : res)
            _res += to_string(i);
        return _res;
    }
};

int main() {
    string s = "zerozero";
    Solution solve;
    string res = solve.originalDigits(s);
    cout << res << endl;
}