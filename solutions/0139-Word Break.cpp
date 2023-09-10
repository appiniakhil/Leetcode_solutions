class Solution {
public:
    //Time Complexity :O(n*n) && Space Complexity :O(n + w), where 'n' is the length of the input string and 'w' is the number of unique words in wordDict
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();

        unordered_set<string> dict;

        for(string word : wordDict)
        {
            dict.insert(word);
        }

        vector<bool> dp(n+1, false);
        dp[0] = true;

        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if (dp[j] && dict.find(s.substr(j, i - j)) != dict.end()) 
                {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[n];
    }
};
