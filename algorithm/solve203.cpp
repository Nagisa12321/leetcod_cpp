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

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() :
        val(0), next(nullptr) {
    }
    ListNode(int x) :
        val(x), next(nullptr) {
    }
    ListNode(int x, ListNode *next) :
        val(x), next(next) {
    }
};
class Solution {
public:
    ListNode *removeElements(ListNode *head, int val) {
        if (!head) return 0;
        else if (head->val == val)
            return removeElements(head->next, val);
        else {
            head->next = removeElements(head->next, val);
            return head;
        }
    }
};