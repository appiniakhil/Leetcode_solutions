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
    //Time Complexit :O(n) && Space Complexity :O(n)
    TreeNode* res;
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        
        if(cloned == NULL)
        {
            return cloned;
        }

        if(cloned->val == target->val)
        {
            res = cloned;
        }

        getTargetCopy(original,cloned->left,target);
        getTargetCopy(original,cloned->right,target);

        return res;
    }
};
