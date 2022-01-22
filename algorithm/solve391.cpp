#include "leetcode.h"
using namespace std;

// struct pair_hash {
//     size_t operator()(const pair<int, int> &p) {
//         size_t a = hash<int>{}(p.first);
//         size_t b = hash<int>{}(p.second);
//         return a ^ b;
//     }
// };

struct pair_hash {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const
    {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);
        return hash1 ^ hash2;
    }
};

class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        int _min_x = 0xffff, _min_y = 0xffff;
        int _max_x = 0x0, _max_y = 0x0;
        unordered_map<pair<int, int>, int, pair_hash> point_map;

        int real_square = 0;
        for (const vector<int> &rect : rectangles) {
            int lx = rect[0], ly = rect[1];
            int rx = rect[2], ry = rect[3];
            int h = ry - ly;
            int w = rx - lx;
            _min_x = min(_min_x, lx);
            _min_y = min(_min_y, ly);
            _max_x = max(_max_x, rx);
            _max_y = max(_max_y, ry);

            point_map[{lx, ly}]++;
            point_map[{lx + w, ly}]++;
            point_map[{lx, ly + h}]++;
            point_map[{rx, ry}]++;

            real_square += h * w;
        }

        int expect_square = (_max_y - _min_y) * (_max_x - _min_x);

        // if the square is not equal, just return false!
        if (real_square != expect_square) {
            return false;
        }


        bool ld = false, lu = false, rd = false, ru = false;
        for (const pair<pair<int, int>, int> &point : point_map) {
            int times = point.second;
            int x = point.first.first;
            int y = point.first.second;
            if (times == 1) {
                if (x == _min_x && y == _min_y) {
                    if (!ld) { ld = true; continue; }
                    else return false;
                }
                if (x == _min_x && y == _max_y) {
                    if (!lu) { lu = true; continue; }
                    else return false;
                }
                if (x == _max_x && y == _min_y) {
                    if (!rd) { rd = true; continue; }
                    else return false;
                }
                if (x == _max_x && y == _max_y) {
                    if (!ru) { ru = true; continue; }
                    else return false;
                }
                return false;
            }
            if (times != 2 && times != 4) {
                return false;
            }
        }
        if (!ld || !lu || !rd || !ru) return false;

        return true;
    }
};

int main() {
    Solution solve;
    vector<vector<int>> vec{{1,1,3,3},{3,1,4,2},{3,2,4,4},{1,3,2,4},{2,3,3,4}};
    bool res = solve.isRectangleCover(vec);
    cout << res << endl;
}