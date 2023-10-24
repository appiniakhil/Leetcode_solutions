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
    //Time Complexity :O(n) && Space Complexity :O(m) where n is the no of nodes and m is the maximum no of nodes on a level
    vector<int> largestValues(TreeNode* root) {
        if(root == NULL)
        {
            return {};
        }

        vector<int> ans;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty())
        {
            int size = q.size();
            int maxi = INT_MIN;

            for(int i=0;i<size;i++)
            {
                TreeNode* node = q.front();
                q.pop();

                maxi = max(maxi, node->val);

                if(node->left != NULL)
                {
                    q.push(node->left);
                }

                if(node->right != NULL)
                {
                    q.push(node->right);
                }
            }

            ans.push_back(maxi);
        }

        return ans;
    }
};
