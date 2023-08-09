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
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root == NULL)
        {
            return NULL;
        }

        if(root->val == val)
        {
            return root;
        }
        else if(root->val > val)
        {
            return searchBST(root->left, val);
        }
        else
        {
            return searchBST(root->right, val);
        }
    }
};
