class Solution {
public:
    //Time Complexity :O(n * m) && Space Complexity :O(1)
    // int countNegatives(vector<vector<int>>& grid) {
    //     int n = grid.size();
    //     int m = grid[0].size();

    //     int cnt = 0;

    //     for(int i=0;i<n;i++)
    //     {
    //         for(int j=0;j<m;j++)
    //         {
    //             if(grid[i][j] < 0)
    //             {
    //                 cnt++;
    //             }
    //         }
    //     }

    //     return cnt;
    // }

    //Time Complexity :O(mlogn) && Space Complexity :O(1)
    int countNegatives(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int cnt = 0;

        for(int i=0;i<n;i++)
        {
            int l = 0, h = m-1;

            while(l <= h)
            {
                int mid = l + (h-l)/2;

                if(grid[i][mid] < 0)
                {
                    h = mid-1;
                }
                else
                {
                    l = mid+1;
                }
            }

            cnt += (m - l);
        }

        return cnt;
    }
};
