#include "leetcode.h"
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        int __start = 0;
        priority_queue<int> __choose;
//
//  Sort the courses by end time
//
        sort(courses.begin(), 
             courses.end(), 
             [](const vector<int> &__lhs, const vector<int> &__rhs) 
                { return __lhs[1] > __rhs[1]; }
            );
        
        for (const vector<int> __course : courses) {
            int __s = __course[0], __e = __course[1];
            __choose.push(__s);
            __start += __s;
            if (__start > __e) {
                int __poll = __choose.top();
                __choose.top();
                __start -= __poll;
            }
        }

        return __choose.size();
    }
};

int main() {
    vector<vector<int>> __case{
        {7, 17}, {3, 12}, {10, 20}, {9, 10}, {5, 20}, {10, 19}, {4, 18}};
    Solution solve;
    int __res = solve.scheduleCourse(__case);
    cout << __res;
}