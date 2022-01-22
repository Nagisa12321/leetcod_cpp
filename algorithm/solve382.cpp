#include "leetcode.h"
#include <vector>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    Solution(ListNode* head) {
        while (head) { 
            v.push_back(head); 
            head = head->next;
        }
    }
    
    int getRandom() {
        if (v.size() == 1) return v[0]->val;
        return v[rand() % (v.size() - 1)]->val;
    }

private:
    vector<ListNode *> v;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */
