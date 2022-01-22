// io
#include <iostream>
#include <cstdlib>
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

#include <iterator>
#include <sstream>

using namespace std;


class Solution {
public:
    bool wordPattern(string pattern, string s) {
        istringstream iss(s);
        istream_iterator<string> it_in(iss), it_eof;
        vector<string> svec(it_in, it_eof);

        unordered_map<char, string> map;
        unordered_map<string, char> map_ref;
        int idx = 0;
        for (char c : pattern) {
            const string &str = svec[idx++];
            if (!map.count(c) && !map_ref.count(str)) {
                map[c] = str;
                map_ref[str] = c;
            } else if (map[c] != str || map_ref[str] != c)
                return false;
        }
        return true;
    }
};