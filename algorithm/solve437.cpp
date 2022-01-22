#include <set>
#include <vector>
using std::set;
using std::vector;

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
    int pathSum(TreeNode *root, int targetSum) {
        vector<int> v;
        this->res = 0;
        dfs(root, targetSum, v);
        return res;
    }

private:
    int res;
    void dfs(TreeNode *root, int targetSum, vector<int> v) {
        if (!root)
            return;
        v.push_back(targetSum);
        
        for (int i : v) 
            if (i == root->val)
                res++;

        vector<int> new_v;
        for (int i : v) 
            new_v.push_back(i - root->val);

        dfs(root->left, targetSum, new_v);
        dfs(root->right, targetSum, new_v);
    }
};