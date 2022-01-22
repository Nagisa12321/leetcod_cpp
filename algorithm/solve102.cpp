#include "leetcode.h"
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() :
        val(0), left(nullptr), right(nullptr) {
    }
    TreeNode(int x) :
        val(x), left(nullptr), right(nullptr) {
    }
    TreeNode(int x, TreeNode *left, TreeNode *right) :
        val(x), left(left), right(right) {
    }
};
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode *root) {
        vector<vector<int>> _res;
        if (!root)
            return _res;
        list<TreeNode *> q;
        q.push_back(root);
        while (!q.empty()) {
            int sz = q.size(); 
            vector<int> vec;
            for (int i = 0; i < sz; ++i) {
                TreeNode *node = q.front();
                q.pop_front();
                vec.push_back(node->val);

                if (node->left) q.push_back(node->left);
                if (node->right) q.push_back(node->right);
            }
            _res.push_back(vec);
        }

        return _res;
    }
};