class Solution {
public:
    //Time Complexity :O(query_row * query_row) && Space Complexity :O(query_row * query_row)
    // double champagneTower(int poured, int query_row, int query_glass) {
    //     vector<vector<double>> glasses(query_row + 1, vector<double>(query_row + 1, 0.0));
    //     glasses[0][0] = poured;

    //     for(int i=0;i<query_row;i++) 
    //     {
    //         for(int j=0;j<=i;j++) 
    //         {
    //             double excess = (glasses[i][j] - 1) / 2.0;
    //             if(excess > 0) 
    //             {
    //                 glasses[i + 1][j] += excess;
    //                 glasses[i + 1][j + 1] += excess;
    //             }
    //         }
    //     }

    //     return min(1.0, glasses[query_row][query_glass]);
    // }

    //Time Complexity :O(query_row * query_row) && Space Complexity :O(query_row * query_row)
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>> dp(query_row + 1, vector<double>(query_row + 1, 0.0));
        dp[0][0] = poured;

        for(int i=0;i<query_row;i++) 
        {
            for(int j=0;j<=i;j++) 
            {
                double excess = max(0.0,(dp[i][j] - 1.0) / 2.0);
                dp[i + 1][j] += excess;
                dp[i + 1][j + 1] += excess;
            }
        }

        return min(1.0, dp[query_row][query_glass]);
    }
};
