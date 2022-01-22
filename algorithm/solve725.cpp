#include <vector>

using std::vector;

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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int len = 0;
        ListNode* cur = head;
        while (cur) {
            cur = cur->next;
            len++;
        }

        int div = len / k;
        int mod = len % k;
        
        cur = head;
        vector<ListNode*> res; 
        for (int i = 0; i < k; i++) {
            res.push_back(cur);
            int sz = div + (mod > 0 ? 1 : 0);
            for (int j = 0; j < sz; j++) {
                if (j == sz - 1) {
                    ListNode* tmp = cur;
                    cur = cur->next;
                    tmp->next = nullptr;
                } else cur = cur->next;
            }
            if (mod > 0)
                --mod;
        }
        return res;
    }
};