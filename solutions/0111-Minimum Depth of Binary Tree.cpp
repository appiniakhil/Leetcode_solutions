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
public:

    //Using Recursion
    //Time Complexity :O(n) && Space Complexity :O(n)
    int minDepth(TreeNode* root) {
        if(root == NULL)
        {
            return 0;
        }
        else if(root->left == NULL && root->right == NULL)
        {
            return 1;
        }
        else if(root->left == NULL)
        {
            return 1 + minDepth(root->right);
        }
        else if(root->right == NULL)
        {
            return 1 + minDepth(root->left);
        }

        int l = minDepth(root->left);
        int r = minDepth(root->right);

        return 1 + min(l, r);
    }
};
