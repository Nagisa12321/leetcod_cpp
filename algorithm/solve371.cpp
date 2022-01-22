class Solution {
public:
    int getSum(int a, int b) {
        int cf = 0, res = 0;
        for (int i = 0; i < 32; i++) {
            res |= ((a & 1) ^ (b & 1) ^ cf) << i;
            cf = cf ? ((a & 1) || (b & 1)) : ((a & 1) && (b & 1));
            a >>= 1;
            b >>= 1;
        }

        return res;
    }
};