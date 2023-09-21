class Solution {
public:
    //Time Complexity :O(n * m) && Space Complexity :O(n * m)
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int, int>> q;
        int cnt = 0;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j] == 2)
                {
                    q.push({i, j});
                }
                else if(grid[i][j] == 1)
                {
                    cnt++;
                }
            }
        }

        int tm = 0;
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};

        while(!q.empty() && cnt > 0) 
        {
            int size = q.size();
            bool flag = false;

            for(int k=0;k<size;k++)
            {
                int r = q.front().first;
                int c = q.front().second;
                q.pop();

                for(int i=0;i<4;i++)
                {
                    int nrow = r + drow[i];
                    int ncol = c + dcol[i];

                    if(nrow >=0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == 1)
                    {
                        grid[nrow][ncol] = 2;
                        q.push({nrow, ncol});
                        cnt--;
                        flag = true;
                    }
                }
            }
            
            if(flag)
            {
                tm++;
            }
        }

        if(cnt != 0)
        {
            return -1;
        }

        return tm;
    }
};
