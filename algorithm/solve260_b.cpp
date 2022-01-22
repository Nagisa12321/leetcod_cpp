#include "leetcode.h"
using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long _xor, _bit;
        for (int i : nums) _xor ^= i;
        for (_bit = 0; !(_xor >> _bit & 0x1); ++_bit);
        long long _res1 = 0, _res2 = 0;
        for (int i : nums) 
            if (i >> _bit & 0x1) _res1 ^= i;
            else _res2 ^= i; 
        return {(int)_res1, (int)_res2};
    }
};