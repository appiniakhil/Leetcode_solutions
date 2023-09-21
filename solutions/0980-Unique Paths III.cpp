class Solution {
public:
    //Time Complexity :O(n * m) && Space Complexity :O(n * m)
    void dfs(vector<vector<int>>& grid, int i, int j, int ex, int ey,int totEmpty, int& paths,vector<vector<bool>>& vis)
    {
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == -1 || vis[i][j])
        {
            return ;
        }

        if(i == ex && j == ey)
        {
            if(totEmpty == -1)
            {
                paths++;
            }
            return; 
        }

        vis[i][j] = true;

        int orgVal = grid[i][j];
        totEmpty--;

        dfs(grid,i+1,j,ex,ey,totEmpty,paths,vis);
        dfs(grid,i-1,j,ex,ey,totEmpty,paths,vis);
        dfs(grid,i,j+1,ex,ey,totEmpty,paths,vis);
        dfs(grid,i,j-1,ex,ey,totEmpty,paths,vis);

        vis[i][j] = false;
    }

    int uniquePathsIII(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int totEmpty = 0;

        int sx = 0, sy = 0, ex = 0, ey = 0;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j] == 1)
                {
                    sx = i;
                    sy = j;
                }
                else if(grid[i][j] == 2)
                {
                    ex = i;
                    ey = j;
                }
                else if(grid[i][j] == 0)
                {
                    totEmpty++;
                }
            }
        }

        int paths = 0;
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        dfs(grid,sx,sy,ex,ey,totEmpty,paths,vis);

        return paths;
    }
};
