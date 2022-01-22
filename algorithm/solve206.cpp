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
    ListNode *reverseList(ListNode *head) {
        if (!head) return 0;
        else if (!head->next) return head;
        ListNode *_res = reverseList(head->next);
        head->next->next = head;
        head->next = 0;
        return _res;
    }
};