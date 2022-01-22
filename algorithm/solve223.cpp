#include <vector>
#include <algorithm>

using std::vector;
using std::sort;

class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        vector<int> v1 = {ax1, ay1, ax2, ay2};
        vector<int> v2 = {bx1, by1, bx2, by2};
        int area1 = (ax2 - ax1) * (ay2 - ay1);
        int area2 = (bx2 - bx1) * (by2 - by1);
        int res = area1 + area2;
        if (!isRectangleOverlap(v1, v2)) 
            return res;

        vector<int> v3 = {ax1, ax2, bx1, bx2};
        vector<int> v4 = {ay1, ay2, by1, by2};
        sort(v3.begin(), v3.end());
        sort(v4.begin(), v4.end());

        int x = v3[2] - v3[1];
        int y = v4[2] - v4[1];

        res -= x * y;
        return res;
    }
    bool isRectangleOverlap(vector<int> &rec1, vector<int> &rec2) {
        if (rec1[0] == rec1[2] || rec1[1] == rec1[3] || rec2[0] == rec2[2] || rec2[1] == rec2[3]) {
            return false;
        }
        return !(rec1[2] <= rec2[0] || // left
                 rec1[3] <= rec2[1] || // bottom
                 rec1[0] >= rec2[2] || // right
                 rec1[1] >= rec2[3]);  // top
    }
};