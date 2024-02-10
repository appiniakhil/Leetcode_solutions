class Solution {
public:
    //Time Complexity :O(n * n * n) && Space Complexity :O(n)
    // bool isPalindrome(string s)
    // {
    //     int n =s.length();
    //     int i=0,j=n-1;
        
    //     while(i < j)
    //     {
    //         if(s[i] != s[j])
    //         {
    //             return false;
    //         }
    //         i++;
    //         j--;
    //     }

    //     return true;
    // }

    // int countSubstrings(string s) {
    //    int cnt=0, n=s.length();

    //     for(int i=0;i<n;i++) 
    //     {
    //         string subStr;

    //         for (int j=i;j<n;j++) 
    //         {
    //             subStr += s[j];
    //             if(subStr.length() == 1)
    //             {
    //                 cnt++;
    //             }
    //             else if(isPalindrome(subStr))
    //             {
    //                 cnt++;
    //             }
    //         }
    //     } 

    //     return cnt;
    // }

    //Time Complexity :O(n * n) && Space Complexity :O(n * n)
    int countSubstrings(string s) {
        int n = s.length();
        int cnt = 0;

        vector<vector<bool>> dp(n, vector<bool> (n, false));

        for(int i=0;i<n;i++)
        {
            dp[i][i] = true;
            cnt++;

            if(i < n-1 && s[i] == s[i+1])
            {
                dp[i][i+1] = true;
                cnt++;
            }
        }

        for(int len=3;len<=n;len++) 
        {
            for(int i=0;i<=n-len;i++) 
            {
                int j=i+len-1;
                
                if(s[i] == s[j] && dp[i + 1][j - 1]) 
                {
                    dp[i][j] = true;
                    cnt++;
                }
            }
        }

        return cnt;
    }
};
