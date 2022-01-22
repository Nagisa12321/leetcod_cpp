#include "leetcode.h"
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class BSTIterator {
public:
    BSTIterator(TreeNode* root) {
        while (root) {
            s.push(root);
            root = root->left;
        } 
    }
                
    int next() {
        TreeNode *node = s.top();
        s.pop();
        int res = node->val;
        if (node->right) {
            TreeNode *cur = node->right;
            while (cur) {
                s.push(cur);    
                cur = cur->left;
            }
        }
        return res;
    }
                    
    bool hasNext() {
        return s.empty();
    }
private:
    stack<TreeNode *> s; 
};


