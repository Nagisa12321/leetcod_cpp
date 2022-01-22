#include <iostream>
#include <cstdio>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <vector>
#include <forward_list>

using namespace std;

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int lo = 0, hi = arr.size();
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (mid == 0)
                lo = mid + 1;
            else if (mid == arr.size() - 1)
                hi = mid - 1;
            else if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1])
                return mid;
            else if (arr[mid] > arr[mid - 1])
                lo = mid + 1;
            else 
                hi = mid - 1;
        }
        return -1;
    }
};

int main() {
    vector<int> v = {0, 2, 1, 0};
    Solution solve;
    int res = solve.peakIndexInMountainArray(v);
    cout << res << endl;
}