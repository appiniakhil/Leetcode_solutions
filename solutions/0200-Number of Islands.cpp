class Solution {
public:
    //Time Complecity :O(n * n) && Space Complexity :O(n * m)
    void bfs(int row, int col, int n, int m, vector<vector<int>>& vis, vector<vector<char>>& grid)
    {
        vis[row][col] = 1;

        queue<pair<int,int>> q;
        q.push({row, col});

        while(!q.empty())
        {
            int i = q.front().first;
            int j = q.front().second;
            q.pop();

            for(int a = -1;a<=1;a++)
            {
                for(int b = -1;b<=1;b++)
                {
                    int na = i + a;
                    int nb = j + b;

                    if((abs(a-b) == 1) && na >= 0 && na < n && nb >= 0 && nb < m  && grid[na][nb] == '1' && !vis[na][nb])
                    {
                        vis[na][nb] = 1;
                        q.push({na, nb});
                    }
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int> (m ,0));

        int cnt = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!vis[i][j] && grid[i][j] == '1')
                {
                    cnt++;
                    bfs(i, j, n, m, vis, grid);
                }
            }
        }

        return cnt;
    }
};
