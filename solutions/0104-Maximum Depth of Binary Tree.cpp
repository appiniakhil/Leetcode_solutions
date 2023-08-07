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
    //Time Complexity :O(n) && Space Complexity :O(h) where h is the height of the tree
    int maxDepth(TreeNode* root) {
        if(root == NULL)
        {
            return 0;
        }

        int l = maxDepth(root->left);
        int r = maxDepth(root->right);

        return 1 + max(l,r);
    }
};
