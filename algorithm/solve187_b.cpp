#include <vector>
#include <string>
#include <iostream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    const int bits_20 = 0x000fffff;

    /**
     * A -> 00
     * C -> 01
     * G -> 10
     * T -> 11
     */ 
    int get_hex(char c) {
        if (c == 'A') return 0;
        else if (c == 'C') return 1;
        else if (c == 'G') return 2;
        else return 3;
    }

    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<int, int> map;
        vector<string> res;
        if (s.size() < 10) return res;
        int buf = 0;
        for (int i = 0; i < 10; i++) {
            buf <<= 2;
            buf &= get_hex(s[i]);
        }

        for (int i = 0; i <= s.size() - 10; i++) {
            if (map[buf]++ == 1) res.push_back(s.substr(i, 10));
            buf = ((buf << 2) | get_hex(s[i + 10])) & bits_20;
        }
        return res;
    }
};

int main() {
    string s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
    Solution sol;
    vector<string> v = sol.findRepeatedDnaSequences(s);
    for (const string &str : v)
        cout << str << endl;
}