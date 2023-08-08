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
    int findmaxHeight(TreeNode* root, int& maxHeight)
    {
        if(root == NULL)
        {
            return 0;
        }

        int l = findmaxHeight(root->left,maxHeight);

        int r = findmaxHeight(root->right,maxHeight);

        maxHeight = max(maxHeight, l + r);

        return  1 + max(l,r);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int ans = 0;
        findmaxHeight(root, ans);

        return ans;
    }
};
