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
    int kthSmallest(TreeNode *root, int k) {
        dfs(root, k);
        return _k;
    }

    void dfs(TreeNode *node, int k) {
        if (_k != INF || !node)
            return;

        dfs(node->left, k);
        if (_k != INF)
            return;
        if (no == k) {
            _k = node->val;
            return;
        }
        ++no;
        dfs(node->right, k);
    }

private:
    constexpr static int INF = 0xffffcccc;
    int _k = INF;
    int no = 1;
};