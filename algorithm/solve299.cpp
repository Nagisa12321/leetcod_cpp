#include "leetcode.h"
using namespace std;

class Solution {
public:
    string getHint(string secret, string guess) {
        string _res;
        int a = 0, b = 0;
        unordered_map<int, int> map;
        vector<bool> bulls(secret.size(), false);
        for (int i = 0; i < secret.size(); ++i) {
            if (secret[i] == guess[i]) {
                bulls[i] = true;
                ++a;
            } else ++map[secret[i]];
        }

        for (int i = 0; i < guess.size(); ++i) {
            if (bulls[i]) continue;
            if (map.count(guess[i])) {
                ++b;
                --map[guess[i]];
                if (!map[guess[i]])
                    map.erase(guess[i]);
            }
        }
        _res += to_string(a);
        _res += 'A';
        _res += to_string(b);
        _res += 'B';

        return _res;
    }
};
