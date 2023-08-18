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
    void helper(TreeNode* node, int& sum,TreeNode* parent, TreeNode* gparent)
    {
        if(node == NULL)
        {
            return ;
        }
        if(gparent != NULL)
        {
            if(gparent->val%2 == 0)
            {
                sum += node->val;
            }
        }

        helper(node->left,sum,node,parent);
        helper(node->right,sum,node,parent);
    }

    int sumEvenGrandparent(TreeNode* root) {
        if(root == NULL)
        {
            return 0;
        }

        int sum=0;
        helper(root,sum,NULL,NULL);

        return sum;
    }
};
