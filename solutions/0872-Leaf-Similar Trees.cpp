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
    void helper(TreeNode* node, vector<int>& v)
    {
        if(!node)
        {
            return;
        }

        if(!node->left && !node->right)
        {
            v.push_back(node->val);
            return;
        }

        helper(node->left, v);
        helper(node->right, v);
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> r1, r2;

        helper(root1, r1);
        helper(root2, r2);

        return r1 == r2;
    }
};
