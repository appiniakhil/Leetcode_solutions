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
    //Time Complexity: O(n) && Space Complexity:O(n)
    void helper(TreeNode* root, vector<int>& arr)
    {
        if(root == NULL)
        {
            return ;
        }

        arr.push_back(root->val);
        helper(root->left, arr);
        helper(root->right, arr);

    }

    vector<int> findMode(TreeNode* root) {
        vector<int> arr;
        helper(root, arr);

        unordered_map<int, int> freq;
        int maxi = 0;

        for(int val : arr) 
        {
            freq[val]++;
            maxi = max(maxi, freq[val]);
        }
        
        vector<int> res;
        for(const auto& pair : freq) 
        {
            if(pair.second == maxi) 
            {
                res.push_back(pair.first);
            }
        }
        
        return res;
    }
};
