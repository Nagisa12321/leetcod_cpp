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

using namespace std;

class Solution {
public:
    int findComplement(int num) {
        unsigned res = 0;
        unsigned bit = 0;
        while (num) {
            res |= ((~num & 1) << bit++);
            num >>= 1;
        }
        return res;
    }
};