class Solution {
public:

    //Using Recursion
    //Time Complexity  :exponential && Space Complexity :O(n)
    // int helper(int index,bool buy,vector<int>& prices)
    // {
    //     int n = prices.size();
    //     if(index >= n)
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
    //         int selling = prices[index] + helper(index+2,true,prices);
    //         int notSelling = 0 + helper(index+1,false,prices);

    //         return max(selling, notSelling);
    //     }
    // }

    // int maxProfit(vector<int>& prices) {
    //     return helper(0,true,prices);
    // }

    //Using Memorisation
    //Time Complexity :O(n * 2) && Space Complexity :O(n * 2) + O(n)
    // int helper(int index,int buy,vector<int>& prices,vector<vector<int>>& dp)
    // {
    //     int n = prices.size();
    //     if(index >= n)
    //     {
    //         return 0;
    //     }

    //     if(dp[index][buy] != -1)
    //     {
    //         return dp[index][buy];
    //     }

    //     if(buy == 1)
    //     {
    //         int buying = -prices[index] + helper(index+1,0,prices,dp);
    //         int notBuying = 0 + helper(index+1,1,prices,dp);

    //         return dp[index][buy] = max(buying, notBuying);
    //     }
    //     else
    //     {
    //         int selling = prices[index] + helper(index+2,1,prices,dp);
    //         int notSelling = 0 + helper(index+1,0,prices,dp);

    //         return dp[index][buy] = max(selling, notSelling);
    //     }
    // }

    //Using Tabulation
    //Time Complexity :O(n * 2) && Space Complexity :O(n * 2)
    // int maxProfit(vector<int>& prices) {
    //     int n = prices.size();

    //     vector<vector<int>> dp(n+2, vector<int>(2,0));

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
    //                 int selling = prices[index] + dp[index+2][1];
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

        vector<int> cur(2,0), front1(2,0), front2(2,0);

        for(int index=n-1;index>=0;index--)
        {
            for(int buy=0;buy<2;buy++)
            {
                if(buy == 1)
                {
                    int buying = -prices[index] + front1[0];
                    int notBuying = 0 + front1[1];

                    cur[buy] = max(buying, notBuying);
                }
                else
                {
                    int selling = prices[index] + front2[1];
                    int notSelling = 0 + front1[0];

                    cur[buy] = max(selling, notSelling);
                }
            }
            front2 = front1;
            front1 = cur;
        }

        return cur[1];
    } 
};
