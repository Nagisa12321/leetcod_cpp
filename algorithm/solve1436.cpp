#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        map<string, int> m;
        for (vector<string> &v : paths) {
            m[v[0]] = 1;
            if (!m[v[1]])
                m[v[1]] = 0;
        }
        for (auto it = m.cbegin(); it != m.cend(); ++it)
            if (!it->second)
                return it->first;

        return "";
    }
};