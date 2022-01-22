class Solution {
public:
    int arrangeCoins(int n) {
        int line = 0;
        int tmp = 1;
        while (n > tmp) {
            n -= tmp++;
            ++line;
        } 
        return line;
    }
};