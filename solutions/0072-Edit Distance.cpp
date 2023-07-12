class Solution {
public:

    //Using Recursion
    //Time Complexity :exponential && Space Complexity :O(n+m)
    //Memory Limit Exceeded
    // int helper(int index1,int index2,string word1,string word2)
    // {
    //     if(index1 < 0)
    //     {
    //         return index2+1;
    //     }

    //     if(index2 < 0)
    //     {
    //         return index1+1;
    //     }

    //     if(word1[index1] == word2[index2])
    //     {
    //         return 0 + helper(index1-1,index2-1,word1,word2);
    //     }

    //     int insert = 1 + helper(index1,index2-1,word1,word2);
    //     int delet = 1 + helper(index1-1,index2,word1,word2);
    //     int replace = 1 + helper(index1-1,index2-1,word1,word2);

    //     return min(insert,min(delet,replace));
    // }

    // int minDistance(string word1, string word2) {
    //     int n = word1.size();
    //     int m = word2.size();

    //     return helper(n-1,m-1,word1,word2);
    // }

    //Using Memorisation
    //Time Complexity :O(n*m) && Space Complexity :O(n*m) + O(n+m)
    // int helper(int index1,int index2,string word1,string word2,vector<vector<int>>& dp)
    // {
    //     if(index1 < 0)
    //     {
    //         return index2+1;
    //     }

    //     if(index2 < 0)
    //     {
    //         return index1+1;
    //     }

    //     if(dp[index1][index2] != -1)
    //     {
    //         return dp[index1][index2];
    //     }

    //     if(word1[index1] == word2[index2])
    //     {
    //         return dp[index1][index2] = 0 + helper(index1-1,index2-1,word1,word2,dp);
    //     }

    //     int insert = 1 + helper(index1,index2-1,word1,word2,dp);
    //     int delet = 1 + helper(index1-1,index2,word1,word2,dp);
    //     int replace = 1 + helper(index1-1,index2-1,word1,word2,dp);

    //     return dp[index1][index2] = min(insert,min(delet,replace));
    // }

    // int minDistance(string word1, string word2) {
    //     int n = word1.size();
    //     int m = word2.size();

    //     vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
    //     return helper(n-1,m-1,word1,word2,dp);
    // }

    //Using Tabulation
    //Time Complexity :O(n*m) && Space Complexity :O(n*m)
    // int minDistance(string word1, string word2) {
    //     int n = word1.size();
    //     int m = word2.size();

    //     vector<vector<int>> dp(n+1,vector<int>(m+1,0));

    //     for(int index2=1;index2<=m;index2++)
    //     {
    //         dp[0][index2] = index2;
    //     }

    //     for(int index1=1;index1<=n;index1++)
    //     {
    //         dp[index1][0] = index1;
    //     }

    //     for(int index1=1;index1<=n;index1++)
    //     {
    //         for(int index2=1;index2<=m;index2++)
    //         {
    //             if(word1[index1-1] == word2[index2-1])
    //             {
    //                 dp[index1][index2] = 0 + dp[index1-1][index2-1];
    //             }
    //             else
    //             {
    //                 int insert = 1 + dp[index1][index2-1];
    //                 int delet = 1 + dp[index1-1][index2];
    //                 int replace = 1 + dp[index1-1][index2-1];

    //                 dp[index1][index2] = min(insert,min(delet,replace));
    //             }
    //         }
    //     }
    //     return dp[n][m];
    // }

    //Space Optmisation
    //Time Complexity :O(n*m) && Space Complexity :O(m)
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        vector<int> prev(m+1,0), cur(m+1,0);

        for(int index2=0;index2<=m;index2++)
        {
            prev[index2] = index2;
        }

        for(int index1=1;index1<=n;index1++)
        {
            cur[0] = index1;
            for(int index2=1;index2<=m;index2++)
            {
                if(word1[index1-1] == word2[index2-1])
                {
                    cur[index2] = 0 + prev[index2-1];
                }
                else
                {
                    int insert = 1 + cur[index2-1];
                    int delet = 1 + prev[index2];
                    int replace = 1 + prev[index2-1];

                    cur[index2] = min(insert,min(delet,replace));
                }
            }
            prev = cur;
        }

        return prev[m];
    }


};
