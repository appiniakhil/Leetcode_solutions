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
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        //Time Complexity : O(n) && Space Complexity :O(n)
        queue<TreeNode*> q1, q2;

        if(root1) q1.push(root1);
        if(root2) q2.push(root2);

        vector<int> arr;

        while(!q1.empty())
        {
            int size = q1.size();

            for(int i=0;i<size;i++)
            {
                TreeNode* node = q1.front();
                q1.pop();

                arr.push_back(node->val);

                if(node->left)
                {
                    q1.push(node->left);
                }

                if(node->right)
                {
                    q1.push(node->right);
                }
            }
        }

        while(!q2.empty())
        {
            int size = q2.size();

            for(int i=0;i<size;i++)
            {
                TreeNode* node = q2.front();
                q2.pop();

                arr.push_back(node->val);

                if(node->left)
                {
                    q2.push(node->left);
                }

                if(node->right)
                {
                    q2.push(node->right);
                }
            }
        }

        sort(arr.begin(), arr.end());

        return arr;
    }
};
