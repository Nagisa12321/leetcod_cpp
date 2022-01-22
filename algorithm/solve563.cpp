#include "leetcode.h"
using namespace std;

// Definition for a binary tree node.
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
    int findTilt(TreeNode* root) {
        int res = 0;
        map<TreeNode *, int> m;
        sum(root, &m);
        dfs(root, &res, &m);
        return res;
    }

    int sum(TreeNode *node, map<TreeNode *, int> *m) {
        if (!node) return 0;
        int l = sum(node->left, m);
        int r = sum(node->right, m);
        (*m)[node] = l + r + node->val;
        return l + r + node->val;
    }

    void dfs(TreeNode *node, int *res, map<TreeNode *, int> *m) {
        if (!node) return;
        *res += abs((*m)[node->left] - (*m)[node->right]);
        dfs(node->left, res, m);
        dfs(node->right, res, m);
    }
};

int main() {
    TreeNode *node = new TreeNode(4, 
                                  new TreeNode(2, 
                                               new TreeNode(3), 
                                               new TreeNode(5)), 
                                  new TreeNode(9,
                                               0,
                                               new TreeNode(7)));

    Solution solve;
    int res = solve.findTilt(node);
    cout << res << endl;
}