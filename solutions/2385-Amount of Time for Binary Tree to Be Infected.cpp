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
    void undirectedGraph(TreeNode* curr, int parent, unordered_map<int, unordered_set<int>>& mp)
    {
        if(curr == NULL)
        {
            return ;
        }

        if(mp.find(curr->val) == mp.end())
        {
            mp[curr->val] = unordered_set<int>();
        }

        unordered_set<int>& adjList = mp[curr->val];

        if(parent != 0)
        {
            adjList.insert(parent);
        }

        if(curr->left != NULL)
        {
            adjList.insert(curr->left->val);
        }

        if(curr->right != NULL)
        {
            adjList.insert(curr->right->val);
        }

        undirectedGraph(curr->left, curr->val, mp);
        undirectedGraph(curr->right, curr->val, mp);
    }

    int amountOfTime(TreeNode* root, int start) {
        unordered_map<int, unordered_set<int>> mp;

        undirectedGraph(root,0,mp);

        queue<int> q;
        q.push(start);

        int minutes=0;
        unordered_set<int> vis;
        vis.insert(start);

        while(!q.empty())
        {
            int levelSize = q.size();

            while(levelSize > 0)
            {
                int curr = q.front();
                q.pop();


                for(int i : mp[curr])
                {
                    if(vis.find(i) == vis.end())
                    {
                        vis.insert(i);
                        q.push(i);
                    }
                }
                levelSize--;
            }
            minutes++;
        }

        return minutes-1;
    }
};
