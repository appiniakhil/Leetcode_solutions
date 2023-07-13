class Solution {
public:

    //Using Memorisation
    //Time Complexity :O(2^n) && Space Complexity :O(n)
    // int helper(int index,bool buy,vector<int>& prices)
    // {
    //     int n = prices.size();
    //     if(index == n)
    //     {
    //         return 0;
    //     }

    //     if(buy == true)
    //     {
    //         int buying = -prices[index] + helper(index+1,false,prices);
    //         int notBuying = 0 + helper(index+1,true,prices);
    //         return max(buying, notBuying);
    //     }
    //     else
    //     {
    //         int selling = prices[index] + helper(index+1,true,prices);
    //         int notSelling = 0 + helper(index+1,false,prices);
    //         return max(selling, notSelling);
    //     }
    // }
    
    // int maxProfit(vector<int>& prices) {
    //     return helper(0,true,prices);
    // }

    //Using Memorisation
    //Time Complexity :O(n * 2) && Space Complexity :O(n * 2) + O(n)
    // int helper(int index,bool buy,vector<int>& prices,vector<vector<int>>& dp)
    // {
    //     int n = prices.size();
    //     if(index == n)
    //     {
    //         return 0;
    //     }

    //     if(dp[index][buy] != -1)
    //     {
    //         return dp[index][buy];
    //     }

    //     if(buy == true)
    //     {
    //         int buying = -prices[index] + helper(index+1,false,prices,dp);
    //         int notBuying = 0 + helper(index+1,true,prices,dp);
    //         return dp[index][buy] = max(buying, notBuying);
    //     }
    //     else
    //     {
    //         int selling = prices[index] + helper(index+1,true,prices,dp);
    //         int notSelling = 0 + helper(index+1,false,prices,dp);
    //         return dp[index][buy] = max(selling, notSelling);
    //     }
    // }
    
    // int maxProfit(vector<int>& prices) {
    //     int n = prices.size();
    //     vector<vector<int>> dp(n+1,vector<int>(2,-1));
    //     return helper(0,true,prices,dp);
    // }

    //Using Tabulation
    //Time Complexity :O(n * 2) && Space Complexity :O(n*2)
    // int maxProfit(vector<int>& prices) {
    //     int n = prices.size();
    //     vector<vector<int>> dp(n+1,vector<int>(2,0));

    //     for(int buy=0;buy<2;buy++)
    //     {
    //         dp[n][buy] = 0;
    //     }

    //     for(int index=n-1;index>=0;index--)
    //     {
    //         for(int buy=0;buy<2;buy++)
    //         {
    //             if(buy == 1)
    //             {
    //                 int buying = -prices[index] + dp[index+1][0];
    //                 int notBuying = 0 + dp[index+1][1];
    //                 dp[index][buy] = max(buying, notBuying);
    //             }
    //             else
    //             {
    //                 int selling = prices[index] + dp[index+1][1];
    //                 int notSelling = 0 + dp[index+1][0];
    //                 dp[index][buy] = max(selling, notSelling);
    //             }
    //         }
    //     }
    //     return dp[0][1];
    // }

    //Using Space Optimisation
    //Time Complexity :O(n * 2) && Space Complexity :O(1)
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int>cur(2, 0) , front(2, 0);

        for(int buy=0;buy<2;buy++)
        {
            front[buy] = 0;
        }

        for(int index=n-1;index>=0;index--)
        {
            for(int buy=0;buy<2;buy++)
            {
                if(buy == 1)
                {
                    int buying = -prices[index] + front[0];
                    int notBuying = 0 + front[1];
                    cur[buy] = max(buying, notBuying);
                }
                else
                {
                    int selling = prices[index] + front[1];
                    int notSelling = 0 + front[0];
                    cur[buy] = max(selling, notSelling);
                }
            }

            front = cur;
        }
        return front[1];
    }
};
