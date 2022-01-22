#include "leetcode.h"
#include <queue>
using namespace std;

//
// Definition for a binary tree node.
//
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode *> q;
        q.push(root);
        int inf = 0xffff;
        int floor = 0;
        while (!q.empty()) {
            int size = q.size();
            int prev = inf;
            for (int i = 0; i < size; ++i) {
                TreeNode *poll = q.front();
                q.pop();
                if (floor % 2 == 0) {
                    if (poll->val % 2 == 0) 
                        return false;
                } else {
                    if (poll->val % 2 == 1) 
                        return false;
                }

                if (prev == inf) {
                    prev = poll->val;
                } else {
                    if (floor % 2 == 0) {
                        if (prev >= poll->val)
                            return false;
                    } else {
                        if (prev <= poll->val) 
                            return false;
                    }
                    prev = poll->val;
                }

                if (poll->left) q.push(poll->left);
                if (poll->right) q.push(poll->right);
            }

            ++floor;
        }

        return true;
    }
};
