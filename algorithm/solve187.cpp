#include <vector>
#include <string>
#include <iostream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string, int> map;
        vector<string> res;
        if (s.size() < 10) return res;
        for (int i = 0; i <= s.size() - 10; i++) {
            string tmp = s.substr(i, 10);
            if (map[tmp] == 1) res.push_back(tmp);
            map[tmp]++;
        }
        return res;
    }
};

int main() {
    string s = "AAAAAAAAAAA";
    Solution sol;
    vector<string> v = sol.findRepeatedDnaSequences(s);
    for (const string &str : v)
        cout << str << endl;
}