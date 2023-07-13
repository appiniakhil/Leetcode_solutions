class Solution {
public:

    //Using Recursion
    //Time Complexity :exponential && Space Complexity :O(n+m)
    //Time Limit Exceeded
    // bool helper(int index1,int index2,string& s,string& p)
    // {
    //     if(index1<0 && index2<0)
    //     {
    //         return true;
    //     }

    //     if(index1>=0 && index2<0)
    //     {
    //         return false;
    //     }

    //     if(index1 < 0 && index2 >= 0)
    //     {
    //         for(int i=0;i<=index2;i++)
    //         {
    //             if(p[i] != '*')
    //             {
    //                 return false;
    //             }
    //         }

    //         return true;
    //     }

    //     if(s[index1] == p[index2] || p[index2] == '?')
    //     {
    //         return helper(index1-1,index2-1,s,p);
    //     }
            
    //     if(p[index2] == '*')
    //     {
    //         return helper(index1-1,index2,s,p) || helper(index1,index2-1,s,p);
    //     }
        
    //     return false;
    // }

    // bool isMatch(string s, string p) {
    //     int n = s.size();
    //     int m = p.size();
    //     return helper(n-1,m-1,s,p);
    // }

    //Using Memorisation
    //Time Complexity :O(n*m) && Space Complexity : O(n*m) + O(n+m)
    // bool helper(int index1,int index2,string& s,string& p,vector<vector<int>>& dp)
    // {
    //     if(index1<0 && index2<0)
    //     {
    //         return true;
    //     }

    //     if(index1>=0 && index2<0)
    //     {
    //         return false;
    //     }

    //     if(index1 < 0 && index2 >= 0)
    //     {
    //         for(int i=0;i<=index2;i++)
    //         {
    //             if(p[i] != '*')
    //             {
    //                 return false;
    //             }
    //         }

    //         return true;
    //     }

    //     if(dp[index1][index2] != -1)
    //     {
    //         return dp[index1][index2];
    //     }

    //     if(s[index1] == p[index2] || p[index2] == '?')
    //     {
    //         return dp[index1][index2] = helper(index1-1,index2-1,s,p,dp);
    //     }
            
    //     if(p[index2] == '*')
    //     {
    //         return dp[index1][index2] = helper(index1-1,index2,s,p,dp) || helper(index1,index2-1,s,p,dp);
    //     }
        
    //     return dp[index1][index2] = false;
    // }

    // bool isMatch(string s, string p) {
    //     int n = s.size();
    //     int m = p.size();

    //     vector<vector<int>> dp(n+1,vector<int>(m+1,-1));

    //     return helper(n-1,m-1,s,p,dp);
    // }

    //Using Tabulation
    //Time Complexity :O(n*m) && Space Complexity :O(n*m)
    // bool isMatch(string s, string p) {
    //     int m = s.size();
    //     int n = p.size();

    //     vector<vector<bool>> dp(n+1, vector<bool> (m+1,0));

    //     dp[0][0] = 1;

    //     for(int index2=1;index2<=m;index2++)
    //     {
    //         dp[0][index2] = false;
    //     } 

    //     for(int index1=1;index1<=n;index1++)
    //     {
    //         int flag = true;
    //         for(int k=1;k<=index1;k++)
    //         {
    //             if(p[k-1] != '*')
    //             {
    //                 flag = false;
    //                 break;
    //             }
    //         }
    //         dp[index1][0] = flag;
    //     }

    //     for(int index1=1;index1<=n;index1++)
    //     {
    //         for(int index2=1;index2<=m;index2++)
    //         {
    //             if(p[index1-1] == s[index2-1] || p[index1-1]=='?') 
    //             {
    //                 dp[index1][index2] = dp[index1-1][index2-1];
    //             }
    //             else if(p[index1-1] == '*')
    //             {
    //                 dp[index1][index2] = dp[index1-1][index2] || dp[index1][index2-1];
    //             }
    //             else 
    //             {
    //                 dp[index1][index2] = false;
    //             }
    //         }
    //     }

    //     return dp[n][m];
    // }

    //Space Optimisation
    //Time Complexity :O(n*m) && Space Complexity : O(m)
    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();

        vector<bool> prev(m+1,0), cur(m+1,0);

        prev[0] = 1;

        for(int index2=1;index2<=m;index2++)
        {
            prev[index2] = false;
        } 

        for(int index1=1;index1<=n;index1++)
        {
            int flag = true;
            for(int k=1;k<=index1;k++)
            {
                if(p[k-1] != '*')
                {
                    flag = false;
                    break;
                }
            }
            cur[0] = flag;

            for(int index2=1;index2<=m;index2++)
            {
                if(p[index1-1] == s[index2-1] || p[index1-1]=='?') 
                {
                    cur[index2] = prev[index2-1];
                }
                else if(p[index1-1] == '*')
                {
                    cur[index2] = prev[index2] || cur[index2-1];
                }
                else 
                {
                    cur[index2] = false;
                }
            }
            prev = cur;
        }

        return prev[m];
    }
};
