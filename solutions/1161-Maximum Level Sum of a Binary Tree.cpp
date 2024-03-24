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
    //Time Complexity: O(n) && Space Complexity: O(n), where n is the number of nodes in the binary tree.
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int sum = INT_MIN;
        int smallLevel = 0;
        int maxi = INT_MIN;
        int level = 0;

        while(!q.empty())
        {
            int size = q.size();
            sum = 0;

            for(int i=0;i<size;i++)
            {
                TreeNode* node = q.front();
                q.pop();

                sum += node->val;

                if(node->left)
                {
                    q.push(node->left);
                }

                if(node->right)
                {
                    q.push(node->right);
                }
            }

            level++;
            
            if(sum > maxi)
            {
                maxi = sum;
                smallLevel = level;
            }
        }

        return smallLevel;
    }
};
