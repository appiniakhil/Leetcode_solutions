class Solution {
public:

    //Using Recursion
    //Time Complexity :exponential && Space Complexity :O(n)
    //Time Limit Exceeded
    // int helper(int index,bool buy,int maxtransaction,vector<int>& prices)
    // {
    //     int n = prices.size();

    //     if(maxtransaction == 0)
    //     {
    //         return 0;
    //     }

    //     if(index == n)
    //     {
    //         return 0;
    //     }

    //     if(buy == true)
    //     {
    //         int buying = -prices[index] + helper(index+1,false,maxtransaction,prices);
    //         int notBuying = 0 + helper(index+1,true,maxtransaction,prices);

    //         return max(buying, notBuying);
    //     }
    //     else
    //     {
    //         int selling = prices[index] + helper(index+1,true,maxtransaction-1,prices);
    //         int notSelling = 0 + helper(index+1,false,maxtransaction,prices);

    //         return max(selling, notSelling);
    //     }

    // }


    // int maxProfit(int k, vector<int>& prices) {
    //     return helper(0,true,k,prices);
    // }


    //Using Memorisation
    //Time Complexity :O(n * 2 * k) && Space Complexity :O(n * 2 * k) + O(n)
    // int helper(int index,bool buy,int maxtransaction,vector<int>& prices,vector<vector<vector<int>>>& dp)
    // {
    //     int n = prices.size();

    //     if(maxtransaction == 0)
    //     {
    //         return 0;
    //     }

    //     if(index == n)
    //     {
    //         return 0;
    //     }

    //     if(dp[index][buy][maxtransaction] != -1)
    //     {
    //         return dp[index][buy][maxtransaction];
    //     }

    //     if(buy == true)
    //     {
    //         int buying = -prices[index] + helper(index+1,false,maxtransaction,prices,dp);
    //         int notBuying = 0 + helper(index+1,true,maxtransaction,prices,dp);

    //         return dp[index][buy][maxtransaction] = max(buying, notBuying);
    //     }
    //     else
    //     {
    //         int selling = prices[index] + helper(index+1,true,maxtransaction-1,prices,dp);
    //         int notSelling = 0 + helper(index+1,false,maxtransaction,prices,dp);

    //         return dp[index][buy][maxtransaction] = max(selling, notSelling);
    //     }

    // }

    // int maxProfit(int k, vector<int>& prices) {
    //     int n = prices.size();

    //     vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(k+1,-1)));
    //     return helper(0,true,k,prices,dp);
    // }

    //Using Tabulation
    //Time Complexity :O(n * 2 * k) && Space Complexity :O(n * 2 * k)
    // int maxProfit(int k, vector<int>& prices) {
    //     int n = prices.size();

    //     vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(k+1,0)));

    //     for(int index=0;index<n;index++)
    //     {
    //         for(int buy=0;buy<2;buy++)
    //         {
    //             dp[index][buy][0] = 0;
    //         }
    //     }
        
    //     for(int buy=0;buy<2;buy++)
    //     {
    //         for(int maxtransaction=0;maxtransaction<=k;maxtransaction++)
    //         {
    //             dp[n][buy][maxtransaction] = 0;
    //         }
    //     }

    //     for(int index=n-1;index>=0;index--)
    //     {
    //         for(int buy=0;buy<2;buy++)
    //         {
    //             for(int maxtransaction=1;maxtransaction<=k;maxtransaction++)
    //             {
    //                 if(buy == 1)
    //                 {
    //                     int buying = -prices[index] + dp[index+1][0][maxtransaction];
    //                     int notBuying = 0 + dp[index+1][1][maxtransaction];

    //                     dp[index][buy][maxtransaction] = max(buying, notBuying);
    //                 }
    //                 else
    //                 {
    //                     int selling = prices[index] + dp[index+1][1][maxtransaction-1];
    //                     int notSelling = 0 + dp[index+1][0][maxtransaction];

    //                     dp[index][buy][maxtransaction] = max(selling, notSelling);
    //                 }
    //             }
    //         }
    //     }

    //     return dp[0][1][k];
    // }

    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();

        vector<vector<int>> cur(2, vector<int>(k+1,0));
        vector<vector<int>> front(2, vector<int>(k+1,0));

        for(int index=n-1;index>=0;index--)
        {
            for(int buy=0;buy<2;buy++)
            {
                for(int maxtransaction=1;maxtransaction<=k;maxtransaction++)
                {
                    if(buy == 1)
                    {
                        int buying = -prices[index] + front[0][maxtransaction];
                        int notBuying = 0 + front[1][maxtransaction];

                        cur[buy][maxtransaction] = max(buying, notBuying);
                    }
                    else
                    {
                        int selling = prices[index] + front[1][maxtransaction-1];
                        int notSelling = 0 + front[0][maxtransaction];

                        cur[buy][maxtransaction] = max(selling, notSelling);
                    }
                }
            }

            front  = cur;
        }

        return front[1][k];
    }
};
