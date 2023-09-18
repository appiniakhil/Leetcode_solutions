/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class BSTIterator {
private:
    //Time Complexity :O(1) && Space Compexity :O(h) where h is the height of the tree
    stack<TreeNode*> s;

public:
    BSTIterator(TreeNode* root) {
        // Initialize the stack with all leftmost nodes
        while (root != NULL) {
            s.push(root);
            root = root->left;
        }
    }

    bool hasNext() {
        return !s.empty();
    }

    int next() {
        TreeNode* node = s.top();
        s.pop();

        TreeNode* right = node->right;
        while (right != NULL) 
        {
            s.push(right);
            right = right->left;
        }

        return node->val;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
