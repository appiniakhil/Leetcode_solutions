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
    map<int, int> mp;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        for(int i=0;i<inorder.size();i++)
        {
            mp[inorder[i]] = i;
        }

        TreeNode* root = helper(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1);

        return root;
    }

    TreeNode* helper(vector<int>& preorder, int preS, int preE, vector<int>& inorder, int inS, int inE)
    {
        if(preS > preE || inS > inE)
        {
            return NULL;
        }

        TreeNode* root = new TreeNode(preorder[preS]);

        int inR = mp[preorder[preS]];
        int numsL = inR - inS;

        root->left = helper(preorder,preS+1,preS + numsL, inorder, inS,inR - 1);
        root->right = helper(preorder,preS+numsL+1,preE, inorder, inR+1,inE);

        return root;
    }
};
