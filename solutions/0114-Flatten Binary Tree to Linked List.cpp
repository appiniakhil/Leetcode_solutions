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
    // void flatten(TreeNode* root) {
    //     if (root == NULL) 
    //     {
    //         return;
    //     }

    //     TreeNode* temp = root->right;

    //     root->right = root->left;
    //     root->left = NULL;

    //     TreeNode* curr = root;
    //     while (curr->right != NULL) 
    //     {
    //         curr = curr->right;
    //     }

    //     curr->right = temp;

    //     flatten(root->right);
    // }

    //Time Complexity :O(n) && Space Complexity :O(n)
    // TreeNode* prev = NULL;
    // void flatten(TreeNode* root) {
    //     if (root == NULL) 
    //     {
    //         return;
    //     }

    //     flatten(root->right);
    //     flatten(root->left);

    //     root->right = prev;
    //     root->left = NULL;

    //     prev = root;
    // }

    //Using Stack
    //Time Complexity :O(n) && Space Complexity :O(n)
    void flatten(TreeNode* root) {
        stack<TreeNode*> s;
        if (root == NULL) 
        {
            return;
        }

        s.push(root);

        while(!s.empty())
        {
            TreeNode* curr = s.top();
            s.pop();

            if(curr->right)
            {
                s.push(curr->right);
            }

            if(curr->left)
            {
                s.push(curr->left);
            }

            if(!s.empty())
            {
                curr->right = s.top();
            }

            curr->left = NULL;
        }
    }
};
