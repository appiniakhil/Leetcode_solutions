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
    //Time Complexity :O(n) && Space Complexity :O(n)
    int helper(TreeNode* node, int miniN, int maxiN)
    {
        if(!node)
        {
            return maxiN - miniN;
        }

        miniN = min(miniN, node->val);
        maxiN = max(maxiN, node->val);

        return max(helper(node->left, miniN, maxiN), helper(node->right, miniN, maxiN));
    }

    int maxAncestorDiff(TreeNode* root) {
        int miniN = INT_MAX, maxiN = INT_MIN;

        return helper(root, miniN, maxiN);    
    }
};
