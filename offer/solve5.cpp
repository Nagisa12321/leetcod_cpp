#include <vector>
#include <string>
#include <algorithm>
using std::string;
using std::vector;
using std::max;

class Solution {
public:
    int maxProduct(vector<string> &words) {
        vector<int> maps(words.size());
        for (int i = 0; i < words.size(); i++) {
            for (char ch : words[i])
                maps[i] |= (1 << (ch - 'a'));
        }

        size_t res = 0;
        for (int i = 0; i < words.size() - 1; i++) {
            for (int j = i + 1; j < words.size(); j++) {
                if (!(maps[i] & maps[j])) {
                    res = max(words[i].size() * words[j].size(), res);
                }
            }
        }

        return res;
    }
};