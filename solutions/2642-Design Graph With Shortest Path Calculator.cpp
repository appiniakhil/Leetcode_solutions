class Graph {
private:
    int n;
    vector<vector<pair<int,int>>> adj;
public:
    //Time Complexity :O(E) && Space Complexity :O(V + E) where E is the number of edges and V is the number of vertices
    Graph(int n, vector<vector<int>>& edges) {
        this->n = n;
        adj.resize(n);

        for(auto& i : edges)
        {
            addEdge(i);
        }
    }
    
    //Time Complexity :O(1) && Space Complexity :O(1)
    void addEdge(vector<int> edge) {
        adj[edge[0]].push_back({edge[1], edge[2]});
    }
    
    //Time Complexity :O((V + E) log V) && Space Complexity :O(V) where E is the number of edges and V is the number of vertices
    int shortestPath(int node1, int node2) {
        vector<int> dist(n, INT_MAX);

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        dist[node1] = 0;
        pq.push({0, node1});

        while(!pq.empty())
        {
            int u = pq.top().second;
            pq.pop();

            for(auto& i : adj[u])
            {
                int v = i.first;
                int weight = i.second;

                if(dist[v] > dist[u] + weight)
                {
                    dist[v] = dist[u] + weight;

                    pq.push({dist[v], v});
                }
            }
        }

        if(dist[node2] != INT_MAX)
        {
            return dist[node2];
        }

        return -1;
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */
