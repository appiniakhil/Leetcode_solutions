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
class Solution {
    //Time Complexity :O(n) && Space Complexity :O(n)
private:
    TreeNode* first = NULL;
    TreeNode* second = NULL;
    TreeNode* prev = NULL;

public:
    void inOrder(TreeNode* root)
    {
        if(root == NULL)
        {
            return ;
        }

        inOrder(root->left);
        
        if(prev != NULL && prev->val >= root->val)
        {
            if(first == NULL)
            {
                first = prev;
            }
            second = root;
        }

        prev = root;

        inOrder(root->right);
    }

    void recoverTree(TreeNode* root) {
        inOrder(root);

        if(first != NULL && second != NULL)
        {
            swap(first->val, second->val);
        }
    }
};
