// io
#include <iostream>
#include <sstream>
#include <fstream>
#include <cstdlib>
#include <cstdio>

// containers
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <vector>
#include <forward_list>

// algorithm
#include <algorithm>
#include <iterator>
#include <numeric>

// memory
#include <memory>

using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> _res(numRows);
        _res[0] = { 1 };
        for (int i = 1; i < numRows; ++i) {
            vector<int> ivec(i + 1);
            for (int j = 1; j < i; ++j)
                ivec[j] = _res[i - 1][j - 1] + _res[i - 1][j];
            ivec[0] = ivec[i] = 1;
            _res[i] = ivec;
        }
        return _res;
    }
};