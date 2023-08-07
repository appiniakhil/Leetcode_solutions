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
    // void helper(TreeNode* root, vector<int>& ans)
    // {
    //     if(root == NULL)
    //     {
    //         return ;
    //     }

    //     helper(root->left,ans);
    //     ans.push_back(root->val);
    //     helper(root->right,ans);
    // }

    // vector<int> inorderTraversal(TreeNode* root) {
    //     vector<int> ans;
    //     helper(root, ans);

    //     return ans;
    // }

    //Iterative Solution
    //Time Complexity :O(n) && Space Complexity :O(n)
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        
        stack<TreeNode*> st;
        TreeNode* node = root;

        while(true)
        {
            if(node != NULL)
            {
                st.push(node);
                node = node->left;
            }
            else
            {
                if(st.empty() == true) break;
                node = st.top();
                st.pop();
                ans.push_back(node->val);
                node = node->right;
            }
        }

        return ans;
    }
};
