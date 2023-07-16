class Solution {
public:

    //Using Recursion
    //Time Complexity: exponential && Space Complexity :O(m)
    // int helper(int index1, int index2,vector<int>& cuts)
    // {
    //     if(index1 > index2)
    //     {
    //         return 0;
    //     }

    //     int mini = INT_MAX;
    //     for(int ind = index1;ind<=index2;ind++)
    //     {
    //         int cost = cuts[index2+1] - cuts[index1-1] + helper(index1,ind-1,cuts) + helper(ind+1,index2, cuts);
    //         mini = min(mini, cost);
    //     }

    //     return mini;
    // }

    // int minCost(int n, vector<int>& cuts) {
    //     int m = cuts.size();

    //     cuts.push_back(n);

    //     cuts.insert(cuts.begin(), 0);

    //     sort(cuts.begin(), cuts.end());

    //     return helper(1,m,cuts);
    // }

    //Using Memorisation
    //Time Complexity :O(m*m*m) && Space Complexity :O(m * m) + O(m)
    // int helper(int index1, int index2,vector<int>& cuts,vector<vector<int>>& dp)
    // {
    //     if(index1 > index2)
    //     {
    //         return 0;
    //     }

    //     if(dp[index1][index2] != -1)
    //     {
    //         return dp[index1][index2];
    //     }

    //     int mini = INT_MAX;
    //     for(int ind = index1;ind<=index2;ind++)
    //     {
    //         int cost = cuts[index2+1] - cuts[index1-1] + helper(index1,ind-1,cuts,dp) + helper(ind+1,index2, cuts,dp);
    //         mini = min(mini, cost);
    //     }

    //     return dp[index1][index2] =  mini;
    // }

    // int minCost(int n, vector<int>& cuts) {
    //     int m = cuts.size();

    //     cuts.push_back(n);

    //     cuts.insert(cuts.begin(), 0);

    //     sort(cuts.begin(), cuts.end());

    //     vector<vector<int>> dp(m+1,vector<int> (m+1,-1));

    //     return helper(1,m,cuts,dp);
    // }

    //Using Tabulation
    //Time Complexity :O(m*m*m) && Space Complexity :O(m * m)
    // int minCost(int n, vector<int>& cuts) {
    //     int m = cuts.size();

    //     cuts.push_back(n);

    //     cuts.insert(cuts.begin(), 0);

    //     sort(cuts.begin(), cuts.end());

    //     vector<vector<int>> dp(m+2,vector<int> (m+2,0));

    //     for(int index1=m;index1>=1;index1--)
    //     {
    //         for(int index2=1;index2<=m;index2++)
    //         {
    //             if(index1 > index2)
    //             {
    //                 continue;
    //             }

    //             int mini = INT_MAX;
    //             for(int ind = index1;ind<=index2;ind++)
    //             {
    //                 int cost = cuts[index2+1] - cuts[index1-1] + dp[index1][ind-1] + dp[ind+1][index2];
    //                 mini = min(mini, cost);
    //             }
    //             dp[index1][index2] = mini;
    //         }
    //     }

    //     return dp[1][m];
    // }

    int minCost(int n, vector<int>& cuts) {
        int m = cuts.size();

        cuts.push_back(n);

        cuts.insert(cuts.begin(), 0);

        sort(cuts.begin(), cuts.end());

        vector<vector<int>> dp(m+2,vector<int> (m+2,0));

        for(int index1=m;index1>=1;index1--)
        {
            for(int index2=1;index2<=m;index2++)
            {
                if(index1 > index2)
                {
                    continue;
                }

                int mini = INT_MAX;
                for(int ind = index1;ind<=index2;ind++)
                {
                    int cost = cuts[index2+1] - cuts[index1-1] + dp[index1][ind-1] + dp[ind+1][index2];
                    mini = min(mini, cost);
                }
                dp[index1][index2] = mini;
            }
        }

        return dp[1][m];
    }
};
