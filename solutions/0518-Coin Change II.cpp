class Solution {
public:

    //Using Recursion
    //Time Complexity :exponential && Space Complexity :O(amount)
    // int helper(int index,int amount,vector<int>& coins)
    // {
    //     if(index == 0)
    //     {
    //         return (amount%coins[0] == 0);
    //     }

    //     int notTake = helper(index-1,amount,coins);
    //     int take = 0;
    //     if(coins[index] <= amount)
    //     {
    //         take = helper(index,amount-coins[index],coins);
    //     }
        
    //     return notTake + take;
    // }

    // int change(int amount, vector<int>& coins) {
    //     int n = coins.size();
    //     return helper(n-1,amount,coins);
    // }

    //Using Memorisation
    //Time Complexity :O(n*amount) && Space Complexiy :O(n*amount) + O(target)
    // int helper(int index,int amount,vector<int>& coins,vector<vector<int>>& dp)
    // {
    //     if(index == 0)
    //     {
    //         return (amount%coins[0] == 0);
    //     }

    //     if(dp[index][amount] != -1)
    //     {
    //         return dp[index][amount];
    //     }

    //     int notTake = helper(index-1,amount,coins,dp);
    //     int take = 0;
    //     if(coins[index] <= amount)
    //     {
    //         take = helper(index,amount-coins[index],coins,dp);
    //     }
        
    //     return dp[index][amount] = notTake + take;
    // }

    // int change(int amount, vector<int>& coins) {
    //     int n = coins.size();
    //     vector<vector<int>> dp(n,vector<int>(amount+1,-1));
    //     return helper(n-1,amount,coins,dp);
    // }

    //Using Tabulation
    //Time Complexity :O(n*amount) && Space Complexiy :O(n*amount)
    // int change(int amount, vector<int>& coins) {
    //     int n = coins.size();
    //     vector<vector<int>> dp(n,vector<int>(amount+1,0));

    //     for(int amt=0;amt<=amount;amt++)
    //     {
    //         dp[0][amt] = (amt%coins[0] == 0);
    //     }
        
    //     for(int index=1;index<n;index++)
    //     {
    //         for(int amt=0;amt<=amount;amt++)
    //         {

    //             int notTake = dp[index-1][amt];
    //             int take = 0;

    //             if(coins[index] <= amt)
    //             {
    //                 take = dp[index][amt-coins[index]];
    //             }
                
    //             dp[index][amt] = notTake + take;               
    //         }
    //     }
        
    //     return dp[n-1][amount];
    // }

    //Space Optimisation
    //Time Complexity :O(n*amount) && Space Complexiy :O(amount)
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<int>prev(amount+1,0), cur(amount+1,0);

        for(int amt=0;amt<=amount;amt++)
        {
            prev[amt] = (amt%coins[0] == 0);
        }
        
        for(int index=1;index<n;index++)
        {
            for(int amt=0;amt<=amount;amt++)
            {

                int notTake = prev[amt];
                int take = 0;

                if(coins[index] <= amt)
                {
                    take = cur[amt-coins[index]];
                }
                
                cur[amt] = notTake + take;               
            }
            prev = cur;
        }
        
        return prev[amount];
    }

};
