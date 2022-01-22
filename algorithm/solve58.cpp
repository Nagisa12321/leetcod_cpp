#include <string>

using std::string;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int state = 0;
        int nums = 0;
        for (char ch : s) {
            if (ch == ' ') {
                state = 0;
            } else {
                if (state == 0) {
                    nums = 1;
                    state = 1;
                } else 
                    nums++;
            }
        }

        return nums;
    }
};

int main() {
    Solution solve;
    int len = solve.lengthOfLastWord("Hello world");
}