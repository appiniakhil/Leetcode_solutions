/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    //Time Complexity :O(h) && Space Complexity :O(1) where h is the height of the tree
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL)
        {
            return NULL;
        }

        int curr = root->val;
        if(curr < p->val && curr < q->val)
        {
            return lowestCommonAncestor(root->right,p,q);
        }

        if(curr > p->val && curr > q->val)
        {
            return lowestCommonAncestor(root->left,p,q);
        }

        return root;
    }
};
