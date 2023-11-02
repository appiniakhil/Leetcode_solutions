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
    //Time Complexity :O(n) && Space Complexity :O(1)
    int cnt = 0;
    pair<int,int> countNodes(TreeNode* node)
    {
        if(node == NULL)
        {
            return {0,0};
        }

        pair<int,int> l = countNodes(node->left);
        pair<int,int> r = countNodes(node->right);
        
        int lSum = l.first;
        int lcnt = l.second;
        int rSum = r.first;
        int rcnt = r.second;

        int totSum = lSum + rSum + node->val;
        int numNodes = 1 + lcnt + rcnt;

        int avg = totSum / numNodes;
        if(avg == node->val)
        {
            cnt++;
        }

        return {totSum, numNodes};
    }

    int averageOfSubtree(TreeNode* root) {
        countNodes(root);

        return cnt;
    }
};
