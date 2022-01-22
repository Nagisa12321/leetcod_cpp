#include "leetcode.h"
using namespace std;

class Solution {
public:
    bool isPerfectSquare(int num) {
        unordered_set<int> set;
        long long i = 0;
        for (;;) {
            if (i * i > INT32_MAX)
                break;
            set.insert(i * i);
            ++i;
        }
        return set.count(num);
    }
};

int main() {
    long long i = 0;
    for (;;) {
        if (i * i > INT32_MAX)
            break;
        cout << i * i << ", ";
        ++i;
    }
}