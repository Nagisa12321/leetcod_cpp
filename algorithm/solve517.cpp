#include <vector>
#include <iostream>
using std::vector;
using std::abs;
using std::max;

class Solution {
public:
    int findMinMoves(vector<int> &machines) {
        int target = 0;
        for (int i : machines)
            target += i;
        if (target % machines.size())
            return -1;

        vector<int> helper(machines.size());
        for (int i = 0; i < machines.size(); i++) {
            if (i == 0)
                helper[i] = machines[i];
            else
                helper[i] = helper[i - 1] + machines[i];
        }

        target /= machines.size();

        int res = 0;
        for (int i = 0; i < machines.size(); i++) {
            int left, right;
            if (i == 0)
                left = 0;
            else
                left = max(helper[i - 1] - i * target, 0);

            if (i == machines.size() - 1)
                right = 0;
            else
                right = max(helper[machines.size() - 1] - helper[i]
                            - ((int)machines.size() - 1 - i) * target, 0);

            res = max(res, left + right);
        }

        return res;
    }
};