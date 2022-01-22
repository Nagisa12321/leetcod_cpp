// Definition for a Node.
class Node {
public:
    int val;
    Node *prev;
    Node *next;
    Node *child;
};

class Solution {
public:
    Node *flatten(Node *head) {
        dfs(head);
        return this->res;
    }

private:
    Node *res;
    Node *cur;
    void addNode(int val) {
        if (!res) {
            res = new Node;
            res->val = val;
            cur = res;
        } else {
            Node *newNode = new Node;
            cur->next = newNode;
            newNode->prev = cur;
            newNode->val = val;

            cur = cur->next;
        }
    }

    void dfs(Node *node) {
        if (!node) 
            return;
        addNode(node->val);
        dfs(node->child);
        dfs(node->next);
    }
};