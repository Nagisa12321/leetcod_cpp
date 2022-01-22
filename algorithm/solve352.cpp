#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <algorithm>

class vec_hash {
public:
    size_t operator()(const std::vector<int> &vec) const {
        std::string res = std::to_string(vec[0]) + std::to_string(vec[1]);
        return std::hash<std::string>()(res);
    }
};

class SummaryRanges {
public:
    SummaryRanges() {
    }

    void addNum(int val) {
        if (s.count(val))
            return;
        s.insert(val);
        if (map.count(val - 1) && map.count(val + 1)) {
            int hi = map[val + 1][1];
            int lo = map[val - 1][0];
            if (map[val - 1][1] != lo)
                map.erase(val - 1);
            if (map[val + 1][0] != hi)
                map.erase(val + 1);
            map[lo][1] = hi;
            map[hi][0] = lo;
        } else if (map.count(val - 1)) {
            int lo = map[val - 1][0];
            if (map[val - 1][1] != lo)
                map.erase(val - 1);
            std::vector<int> v{lo, val};
            map[val] = v;
            map[lo][1] = val;
        } else if (map.count(val + 1)) {
            int hi = map[val + 1][1];
            if (map[val + 1][0] != hi)
                map.erase(val + 1);
            std::vector<int> v{val, hi};
            map[val] = v;
            map[hi][0] = val;
        } else {
            std::vector<int> v{val, val};
            map[val] = v;
        }
    }

    std::vector<std::vector<int>> getIntervals() {
        std::unordered_set<std::vector<int>, vec_hash> set;
        for (auto entry : map) {
            set.insert(entry.second);
        }
        std::vector<std::vector<int>> res(set.begin(), set.end());
        std::sort(res.begin(), res.end());
        return res;
    }

private:
    std::unordered_map<int, std::vector<int>> map;
    std::unordered_set<int> s;
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(val);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */

void show(SummaryRanges &s) {
    std::cout << " -------------- " << std::endl;
    std::vector<std::vector<int>> res = s.getIntervals();
    for (std::vector<int> v : res)
        std::cout << v[0] << ", " << v[1] << std::endl;
}

int main() {
    SummaryRanges s;
    s.addNum(1);
    s.addNum(3);
    s.addNum(2);
    show(s);
    s.addNum(5);
    s.addNum(7);
    s.addNum(6);
    show(s);

    s.addNum(4);
    show(s);
}