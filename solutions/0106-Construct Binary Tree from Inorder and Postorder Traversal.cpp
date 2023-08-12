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
    map<int, int> mp;
    TreeNode* helper(vector<int>& inorder,int inS, int inE, vector<int>& postorder,int posS,int posE)
    {
        if(inS > inE || posS > posE)
        {
            return NULL;
        }

        TreeNode* root = new TreeNode(postorder[posE]);

        int inR = mp[postorder[posE]];

        int numsL = inR - inS;

        root->left = helper(inorder, inS,inR-1,postorder,posS,posS + numsL - 1);
        root->right = helper(inorder,inR+1,inE,postorder,posS + numsL,posE - 1);

        return root;

    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size() != postorder.size())
        {
            return NULL;
        }

        for(int i=0;i<inorder.size();i++)
        {
            mp[inorder[i]] = i;
        }

        TreeNode* root = helper(inorder,0,inorder.size()-1,postorder,0,postorder.size()-1);

        return root;
    }
};
