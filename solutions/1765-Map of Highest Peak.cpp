class Solution {
public:
    //Time Complexity :O(m*n) && Space Complexity :O(m*n)
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m = isWater.size();
        int n = isWater[0].size();

        vector<vector<int>> height(m, vector<int> (n, -1));
        queue<pair<int, int>> q;

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(isWater[i][j])
                {
                    height[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        vector<int> dir = {-1, 0, 1, 0, -1};

        while(!q.empty())
        {
            auto [x, y] = q.front();
            q.pop();

            for(int i=0;i<4;i++)
            {
                int nx = x + dir[i];
                int ny = y + dir[i+1];

                if(nx < 0 || nx >= m || ny < 0 || ny >= n || height[nx][ny] != -1)
                {
                    continue;
                }

                height[nx][ny] = height[x][y] + 1;
                q.push({nx, ny});
            }
        }

        return height;
    }
};
