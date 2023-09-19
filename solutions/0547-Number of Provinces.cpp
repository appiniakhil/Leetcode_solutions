class Solution {
public:
    //Time Complexity :O(n) + O(V + 2E) && Space Complexity :O(n)
    void dfs(int node,vector<int> adj[],int vis[])
    {
        vis[node] = 1;

        for(auto it: adj[node])
        {
            if(!vis[it])
            {
                dfs(it, adj, vis);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();

        vector<int> adj[n];

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i != j && isConnected[i][j] == 1)
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        int vis[n];

        for(int i=0;i<n;i++)
        {
            vis[i] = 0;
        }

        int cnt = 0;

        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                cnt++;
                dfs(i, adj, vis);
            }
        }

        return cnt;
    }
};
