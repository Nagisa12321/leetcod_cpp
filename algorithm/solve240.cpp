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
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int len_i = matrix.size(), len_j = matrix[0].size();
        int i = len_i - 1, j = 0;
        while (i >= 0 && j < len_j) {
            if (matrix[i][j] == target) return true;
            else if (matrix[i][j] > target) --i;
            else ++j;
        }
        return false;
    }
};