class Solution {
public:
    //Time Complexity :O(m + n) && Space Complexity :O(m + n)
    vector<int> adj[100005];
    int in[100005], res[100005];

    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        int m = relations.size();

        for(int i=0;i<m;i++) 
        {
            int x = relations[i][0];
            int y = relations[i][1];

            adj[x].push_back(y);
            in[y]++;
        }

        queue<int> q;
        for(int i=1;i<=n;i++) 
        {
            if(in[i] == 0) 
            {
                q.push(i);
                res[i] = time[i-1];
            }
        }

        while(!q.empty()) 
        {
            int node = q.front();
            q.pop();

            for(auto it: adj[node]) 
            {
                in[it]--;

                if(in[it] == 0) 
                {
                    q.push(it);
                }

                res[it] = max(res[it], res[node] + time[it-1]);
            }
        }

        int ans = 0;
        for(int i=1;i<=n;i++) 
        {
            ans = max(ans, res[i]);
        }
        
        return ans;
    }
};
