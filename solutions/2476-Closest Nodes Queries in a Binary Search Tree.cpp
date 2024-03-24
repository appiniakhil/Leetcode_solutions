class Solution {
public:
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        vector<vector<int>> ans;
        vector<int> tree;

        traverseTree(root, tree);

        sort(tree.begin(), tree.end());

        for(int query : queries) 
        {
            int closestSmaller = findClosestSmaller(tree, query);
            int closestLarger = findClosestLarger(tree, query);
            ans.push_back({closestSmaller, closestLarger});
        }

        return ans;
    }

    void traverseTree(TreeNode* root, vector<int>& tree) 
    {
        if (!root) return;
        traverseTree(root->left, tree);
        tree.push_back(root->val);
        traverseTree(root->right, tree);
    }

    int findClosestSmaller(vector<int>& tree, int query) 
    {
        int low = 0, high = tree.size() - 1;
        int closestSmaller = -1;
        while(low <= high) 
        {
            int mid = low + (high - low) / 2;
            if (tree[mid] <= query) 
            {
                closestSmaller = tree[mid];
                low = mid + 1;
            } 
            else 
            {
                high = mid - 1;
            }
        }

        return closestSmaller;
    }

    int findClosestLarger(vector<int>& tree, int query) 
    {
        int low = 0, high = tree.size() - 1;
        int closestLarger = -1;

        while(low <= high) 
        {
            int mid = low + (high - low) / 2;
            if(tree[mid] >= query) 
            {
                closestLarger = tree[mid];
                high = mid - 1;
            } 
            else 
            {
                low = mid + 1;
            }
        }
        
        return closestLarger;
    }
};

