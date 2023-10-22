class Solution {
public:
    //Time Complexity :O(n) && Space Complexity :O(n)
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        int n = adjacentPairs.size();

        unordered_map<int, vector<int>> graph;

        for(auto& it : adjacentPairs) {
            graph[it[0]].push_back(it[1]);
            graph[it[1]].push_back(it[0]);
        }

        vector<int> ans(n + 1);

        for(auto& [e, adj] : graph) 
        {
            if(adj.size() == 1) 
            {
                ans[0] = e;
                break;
            }
        }

        ans[1] = graph[ans[0]][0];

        for(int i=2;i<ans.size();i++) 
        {
            auto& adj = graph[ans[i - 1]];
            
            if(adj[0] == ans[i-2])
            {
                ans[i] = adj[1];
            }
            else
            {
                ans[i] = adj[0];
            }
        }
        
        return ans;
    }
};
