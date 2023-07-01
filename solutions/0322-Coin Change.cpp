class Solution {
public:

    //Using Recursion
    //Time Complexity :>O(2^n) && Space Complexity :>O(n)
    //Time Limit Exceeded
    // int helper(int index,int amount,vector<int>& coins)
    // {
    //     if(index == 0)
    //     {
    //         if(amount%coins[0] == 0)
    //         {
    //             return amount/coins[0];
    //         }
    //         return 1e9;
    //     }

    //     int notTake = 0 + helper(index-1,amount,coins);

    //     int take = INT_MAX;
    //     if(coins[index] <= amount)
    //     {
    //         take = 1 + helper(index,amount-coins[index],coins);
    //     }

    //     return min(notTake, take);
    // }

    // int coinChange(vector<int>& coins, int amount) {
    //     int n = coins.size();
    //     int res = helper(n-1,amount,coins);
    //     if(res >= 1e9)
    //     {
    //         return -1;
    //     }
    //     return res;
    // }

    //Using Memorisation
    //Time Complexity :O(n * amount) && Space Complecity :O(n * amount) + O(amount)
    // int helper(int index,int amount,vector<int>& coins,vector<vector<int>>& dp)
    // {
    //     if(index == 0)
    //     {
    //         if(amount%coins[0] == 0)
    //         {
    //             return amount/coins[0];
    //         }
    //         return 1e9;
    //     }
    //     if(dp[index][amount] != -1)
    //     {
    //         return dp[index][amount];
    //     }
    //     int notTake = 0 + helper(index-1,amount,coins,dp);

    //     int take = INT_MAX;
    //     if(coins[index] <= amount)
    //     {
    //         take = 1 + helper(index,amount-coins[index],coins,dp);
    //     }

    //     return dp[index][amount] = min(notTake, take);
    // }

    // int coinChange(vector<int>& coins, int amount) {
    //     int n = coins.size();
    //     vector<vector<int>> dp(n,vector<int> (amount+1,-1));
    //     int res = helper(n-1,amount,coins,dp);
    //     if(res >= 1e9)
    //     {
    //         return -1;
    //     }
    //     return res;
    // }

    //Using Tabulation
    //Time Complexity :O(n * amount) && Space Complexity :O(n * amount)
    // int coinChange(vector<int>& coins, int amount) {
    //     int n= coins.size();
        
    //     vector<vector<int>> dp(n,vector<int>(amount+1,0));
        
    //     for(int amt=0; amt<=amount; amt++)
    //     {
    //         if(amt%coins[0] == 0)  
    //         {
    //             dp[0][amt] = amt/coins[0];
    //         }
    //         else 
    //         {
    //             dp[0][amt] = 1e9;
    //         }
    //     }
        
    //     for(int index = 1; index<n; index++)
    //     {
    //         for(int amt = 0; amt<=amount; amt++)
    //         {
    //             int notTake = 0 + dp[index-1][amt];

    //             int take = 1e9;
    //             if(coins[index]<=amt)
    //             {
    //                 take = 1 + dp[index][amt - coins[index]];
    //             }
                    
    //             dp[index][amt] = min(notTake, take);
    //         }
    //     }
        
    //     int res = dp[n-1][amount];
    //     if(res >= 1e9)
    //     {
    //         return -1;
    //     }
    //     return res;
    // }
    
    //Space Optimisation
    //Time Complexity :O(n * amount) && Space Complexity :O(1)
    int coinChange(vector<int>& coins, int amount) {
        int n= coins.size();
            
        vector<int> prev(amount+1,0),cur(amount+1,0);
            
        for(int amt=0; amt<=amount; amt++)
        {
            if(amt%coins[0] == 0)  
            {
                prev[amt] = amt/coins[0];
            }
            else 
            {
                prev[amt] = 1e9;
            }
        }
        
        for(int index = 1; index<n; index++)
        {
            for(int amt = 0; amt<=amount; amt++)
            {
                int notTake = 0 + prev[amt];

                int take = 1e9;
                if(coins[index]<=amt)
                {
                    take = 1 + cur[amt - coins[index]];
                }
                    
                cur[amt] = min(notTake, take);
            }
            prev = cur;
        }
        
        int res = prev[amount];
        if(res >= 1e9)
        {
            return -1;
        }
        return res;
    }

    
};
