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
    void setZeroes(vector<vector<int>>& matrix) {
        int mark = 1;
        int len_i = matrix.size(); 
        int len_j = matrix[0].size();
        for (int j = 0; j < len_j; ++j) {
            if (!matrix[0][j]) {
                mark = 0;
                break;
            }
        }
        for (int i = 0; i < len_i; ++i) {
            if (!matrix[i][0]) {
                matrix[0][0] = 0;
                break;
            }
        }
        for (int i = 1; i < len_i; ++i) {
            for (int j = 1; j < len_j; ++j) {
                if (!matrix[i][j]) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        for (int i = 1; i < len_i; ++i) {
            if (!matrix[i][0]) {
                for (int j = 1; j < len_j; ++j) {
                    matrix[i][j] = 0;
                }
            }
        }

        for (int j = 1; j < len_j; ++j) {
            if (!matrix[0][j]) {
                for (int i = 1; i < len_i; ++i) {
                    matrix[i][j] = 0;
                }
            }
        }

        if (!matrix[0][0]) {
            for (int i = 0; i < len_i; ++i) {
                matrix[i][0] = 0;
            }
        }

        if (!mark) {
            for (int j = 0; j < len_j; ++j) {
                matrix[0][j] = 0;
            }
        }
    }
};