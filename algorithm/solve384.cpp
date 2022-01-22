#include "leetcode.h"
using namespace std;

class Solution {
public:
    Solution(vector<int>& nums) 
        : ivec(nums),
          random(nums)
    {

    }
    
    vector<int> reset() {
        return ivec;
    }
    
    vector<int> shuffle() {
        for (int i = 0; i < random.size(); ++i) {
            int random_index = rand() % (random.size() - i) + i;
            swap(random[random_index], random[i]);
        }
        return random;
    }
private:
    vector<int> ivec;
    vector<int> random;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */