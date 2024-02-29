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
    //Time Complexity :O(n) && Space Complexity :O(m)
    bool isEvenOddTree(TreeNode* root) {

        if(root == NULL) 
        {
            return true;
        }

        queue<TreeNode*> q;
        q.push(root);
        int level = 0;

        while(!q.empty())
        {
            int size = q.size();
            int prev_val = (level % 2 == 0) ? INT_MIN : INT_MAX;

            for(int i=0;i<size;i++)
            {
                TreeNode* node = q.front();
                q.pop();

                if(level % 2 == 0)
                {
                    if(node->val % 2 == 0 || node->val <= prev_val)
                    {
                        return false;
                    }
                }
                else
                {
                    if(node->val % 2 != 0 || node->val >= prev_val)
                    {
                        return false;
                    }
                }

                prev_val = node->val;

                if(node->left)
                {
                    q.push(node->left);
                }

                if(node->right)
                {
                    q.push(node->right);
                }
            }
            ++level;
        }

        return true;
    }
};
