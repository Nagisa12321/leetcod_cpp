#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    string toHex(int num) {
        string s; 
        if (num < 0) 
            num = 0xffffffff & (~(1 << 31))+ num;
        while (num) {
            s.push_back(v[num & 0xf]);
            num >>= 4;
        }
        reverse(s.begin(), s.end());
        return s;
    }
private:
    vector<char> v{'0', '1', '2', '3', '4', '5', '6', '7', 
                   '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};
};

int main() {
    Solution solve;
    string s = solve.toHex(-300);
    cout << s << endl;
}