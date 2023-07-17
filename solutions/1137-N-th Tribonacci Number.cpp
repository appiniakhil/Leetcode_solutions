class Solution {
public:

    //Using Tabulation
    //Time Complexity :O(n) && Space Complexity :O(n)
    int tribonacci(int n) {
        vector<int> dp(n+3,0);
        dp[0] = 0;
        dp[1] = dp[2] = 1;

        for(int i =3;i<=n;i++)
        {
            dp[i] = dp[i-3] + dp[i-2] + dp[i-1];
        }

        return dp[n];
    }
};
