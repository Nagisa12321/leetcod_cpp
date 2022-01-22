#include "leetcode.h"
#include <queue>
using namespace std;

class Solution {
public:

    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        auto cmp = [&](const pair<int, int> &p1, const pair<int, int> &p2) {
            return arr[p1.first] * arr[p2.second] < arr[p2.first] * arr[p1.second];
        };
        priority_queue<pair<int, int>, 
                       vector<pair<int, int>>, 
                       decltype(cmp)> pq(cmp);
        for (int i = 0; i < arr.size(); ++i) pq.push({0, i});
        for (int i = 0; i < k - 1; ++i) {
            pair<int, int> smallest = pq.top();
            pq.pop();
            if (arr[smallest.first + 1] < arr[smallest.second])
                pq.push({smallest.first + 1, smallest.second});
        }
        pair<int, int> smallest = pq.top();
        return {arr[smallest.first], arr[smallest.second]};
    }
};

int main() {
    Solution solve;
    vector<int> input{1, 2, 3, 5};
    vector<int> res = solve.kthSmallestPrimeFraction(input, 3);
    for (int i : res)
        cout << i << " ";
}