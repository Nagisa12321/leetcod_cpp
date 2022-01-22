
#include "leetcode.h"
using namespace std;

class Solution {
public:
    int maxProduct(vector<string>& words) {
        sort(words.begin(), words.end(), [](const string &s1, const string &s2) {
            return s1.size() > s2.size();
        });
        vector<int> word_maps(words.size());
        for (int i = 0; i < words.size(); ++i) {
            const string &word = words[i];
            for (char c : word) {
                word_maps[i] |= 0x1 << (c - 'a');
            }
        }

        int res = 0;
        for (int i = 0; i < words.size() - 1; ++i) {
            for (int j = i + 1; j < words.size(); ++j) {
                const string &word1 = words[i];
                const string &word2 = words[j];
                if (word1.size() * word2.size() < res)
                    continue;
                if ((word_maps[i] & word_maps[j]) == 0) {
                    res = word1.size() * word2.size();
                }
            }
        }
        return res;
    }
};

int main() {
    Solution solve;
    vector<string> svec{"abcw","baz","foo","bar","xtfn","abcdef"};
    int res = solve.maxProduct(svec);
    cout << res << endl;
}