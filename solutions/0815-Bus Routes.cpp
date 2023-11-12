class Solution {
public:
    //Time Complexity :O(n * n) && Space Complexity :O(n)
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if(source == target)
        {
            return 0;
        }

        unordered_map<int, vector<int>> stop;
        for(int i=0;i<routes.size();i++)
        {
            for(int j : routes[i])
            {
                stop[j].push_back(i);
            }
        }

        vector<int> vis(routes.size(), 0);
        queue<int> q;
        q.push(source);
        int buses = 0;

        while(!q.empty())
        {
            int size = q.size();
            buses++;

            for(int i=0;i<size;i++)
            {
                int st = q.front();
                q.pop();

                for(int bus : stop[st])
                {
                    if(vis[bus])
                    {
                        continue;
                    }

                    vis[bus] = 1;

                    for(int nxtstop : routes[bus])
                    {
                        if(nxtstop == target)
                        {
                            return buses;
                        }
                        q.push(nxtstop);
                    }
                }
            }
        }

        return -1;
    }
};
