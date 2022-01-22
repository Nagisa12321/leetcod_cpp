#include "leetcode.h"
#include <queue>
using namespace std;

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size(), m = nums2.size();
        auto cmp = [&](const vector<int> &v1, const vector<int> &v2) {
            return (nums1[v1[0]] + nums2[v1[1]]) > (nums1[v2[0]] + nums2[v2[1]]);
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> q(cmp);
        for (int i = 0; i < n; ++i) {
            q.push({i, 0});
        }
        vector<vector<int>> res;
        for (int i = 0; i < k && !q.empty(); ++i) {
            int _n = q.top()[0];
            int _m = q.top()[1];
            q.pop();
            res.push_back({nums1[_n], nums2[_m]});

            if (_m != nums2.size() - 1)
                q.push({_n, _m + 1});
        }
        return res;
    }
};

int main() {
    Solution solve; 
    vector<int> ivec1{1, 2};
    vector<int> ivec2{3};
    vector<vector<int>> res = solve.kSmallestPairs(ivec1, ivec2, 3);
    for (vector<int> v : res) {
        cout << "(" << v[0] << ", " << v[1] << "), ";
    }
    cout << endl;
}