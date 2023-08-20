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
    TreeNode* helper(int l,int r, vector<int>& nums)
    {
        if(l>r)
        {
            return NULL;
        }

        int maxi = nums[l], idx = l;
        
        for(int i=l;i<=r;i++)
        {
            if(maxi < nums[i])
            {
                idx = i;
                maxi = nums[i];
            }
        }

        TreeNode* node = new TreeNode(maxi);
        node->left = helper(l,idx-1,nums);
        node->right = helper(idx+1,r,nums);

        return node;
    }

    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        int n = nums.size();

        return helper(0,n-1,nums);
    }
};
