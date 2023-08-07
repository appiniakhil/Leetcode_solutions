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
    // void helper(TreeNode* root,vector<int>& ans)
    // {
    //     if(root == NULL)
    //     {
    //         return ;
    //     }

    //     ans.push_back(root->val);
    //     helper(root->left,ans);
    //     helper(root->right,ans);
    // }

    // vector<int> preorderTraversal(TreeNode* root) {
    //     vector<int> ans;
    //     helper(root, ans);

    //     return ans;
    // }


    //Iterative Solution
    //Time Complexity :O(n) && Space Complexity :O(n)
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;

        if(root == NULL)
        {
            return ans;
        }

        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty())
        {
            root = st.top();
            st.pop();
            ans.push_back(root->val);

            if(root->right != NULL)
            {
                st.push(root->right);
            }

            if(root->left != NULL)
            {
                st.push(root->left);
            }
        }

        return ans;
    }
};
