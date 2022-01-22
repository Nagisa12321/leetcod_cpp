#include "leetcode.h"
using namespace std;

class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        string l1 = "qwertyuiop";
        string l2 = "asdfghjkl";
        string l3 = "zxcvbnm";
        vector<set<char>> key_board;
        vector<string> res;
        key_board.push_back(set<char>(l1.begin(), l1.end())); 
        key_board.push_back(set<char>(l2.begin(), l2.end())); 
        key_board.push_back(set<char>(l3.begin(), l3.end())); 
        for (const string &word : words) {
            int line;
            for (int i = 0; i < 3; ++i) {
                if (key_board[i].count(tolower(word[0]))) {
                    line = i;
                    break;
                }
            }
            if (same_line(word, key_board[line]))
                res.push_back(word);
        }
        return res;
    }

    bool same_line(const string &word, const set<char> &line) {
        for (char c : word) 
            if (!line.count(tolower(c)))
                return false;
        return true;
    }
};

int main() {
    Solution solve;
    vector<string> vec{"Alaska"};
    vector<string> _res = solve.findWords(vec);
    for (const string &word : _res)
        cout << word << endl;
}