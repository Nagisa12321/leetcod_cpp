#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int superPow(int a, vector<int>& b) {
        if (a == 1) return 1;
        if (a == 0) return 0;
        if (b == vector<int>{ 1 }) return a % 1337;
        vector<int> res;
        int mod;
        divide(b, res, mod);
        int __res = superPow(a, res) % 1337;  
        if (mod) return (__res * __res * a) % 1337;
        else return (__res * __res) % 1337;
    }

    void divide(const vector<int> ivec, vector<int> &res, int &mod) {
        long long div = 0, bit = 0; 
        for (int i : ivec) {
            div = (div - (bit << 1)) * 10 + i;
            bit = div >> 1;
            if (!(bit == 0 && res.size() == 0)) {
                res.push_back(bit);
            }
        }
        mod = ivec.back() % 2;
    }
};

int main() {
    Solution solve;
    vector<int> ivec{1, 0};
    int res = solve.superPow(2, ivec);
    cout << res;
}