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
    // TreeNode* searchBST(TreeNode* root, int val) {
    //     if(root == NULL)
    //     {
    //         return NULL;
    //     }

    //     if(root->val == val)
    //     {
    //         return root;
    //     }
    //     else if(root->val > val)
    //     {
    //         return searchBST(root->left, val);
    //     }
    //     else
    //     {
    //         return searchBST(root->right, val);
    //     }
    // }

    //Time Complexity :O(logn) && Space Complexity :O(1)
    TreeNode* searchBST(TreeNode* root, int val) {
        while(root != NULL && root->val != val)
        {
            if(root->val < val)
            {
                root = root->right;
            }
            else
            {
                root = root->left;
            }
        }

        return root;
    }
};
