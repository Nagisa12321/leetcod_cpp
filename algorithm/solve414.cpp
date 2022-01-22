#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

constexpr int init = 0xf7f81331;
class Solution {
public:
    int thirdMax(vector<int> &nums) {
        int first = init, second = init, third = init;
        unordered_set<int> set(nums.begin(), nums.end());
        for (int i : set) {
            if (first == init) {
                first = i;
            } else if (second == init) {
                if (i > first) {
                    second = first;
                    first = i;
                } else 
                    second = i;
            } else {
                if (i > first) {
                    third = second;
                    second = first;
                    first = i;
                } else if (i > second) {
                    third = second;
                    second = i;
                } else {
                    if (third == init)
                        third = i;
                    else {
                        if (i > third)
                            third = i;
                    }
                }
            } 
        }

        return third == init ? first : third;
    }
};