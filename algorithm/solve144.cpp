// io
#include <iostream>
#include <sstream>
#include <fstream>
#include <cstdlib>
#include <cstdio>

// containers
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <vector>
#include <forward_list>

// algorithm
#include <algorithm>
#include <iterator>
#include <numeric>

// memory
#include <memory>

using namespace std;

//  Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *fast = head->next;
        ListNode *slow = head;

        while (fast && fast->next) {
            if (fast == slow)
                return true;
            fast = fast->next->next;
            slow = slow->next;
        }

        return false;
    }
};