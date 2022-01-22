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
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        if (r * c != mat.size() * mat[0].size())
            return mat;
        vector<vector<int>> _res(r, vector<int>(c));
        vector<int> vec;
        for (const vector<int> &ivec : mat) {
            for (int i : ivec) {
                vec.push_back(i);
            }
        }

        int idx = 0; 
        for (vector<int> &ivec : _res) {
            for (int &i : ivec) {
                i = vec[idx++];
            }
        }

        return _res;
    }
};