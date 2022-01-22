class Solution {
public:
    int divide(int a, int b) {
        if (a < 0 && b < 0)
            return divide_helper(-(long)a, -(long)b);
        else if (a < 0)
            return -divide_helper(-(long)a, b);
        else if (b < 0)
            return -divide_helper(a, -(long)b);
        else    
            return divide_helper(a, b);
    }

    long divide_helper(long a, long b) {
        if (a < b)
            return 0;
        else 
            return 1 + divide_helper(a - b, b);
    }
};