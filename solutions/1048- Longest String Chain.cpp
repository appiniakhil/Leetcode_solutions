class Solution {
public:

    //Time Complexity :O(n*n*i) && Space Complexity :O(n)
    bool helper(string& s1, string& s2)
    {
        if(s1.size() != s2.size() + 1)
        {
            return false;
        }

        int firstptr = 0;
        int secondptr = 0;

        while(firstptr < s1.size())
        {
            if(s1[firstptr] == s2[secondptr])
            {
                firstptr++;
                secondptr++;
            }
            else
            {
                firstptr++;
            }
        }

        if(firstptr == s1.size() && secondptr == s2.size())
        {
            return true;
        }

        return false;
    }

    static bool compare(string& s1, string& s2)
    {
        return s1.size() < s2.size();
    }

    int longestStrChain(vector<string>& words) {
        int n = words.size();

        sort(words.begin(), words.end(), compare);
        vector<int> dp(n,1);

        int maxi = 1;
        for(int index=1;index<n;index++)
        {
            for(int previndex=0;previndex<index;previndex++)
            {
                if(helper(words[index], words[previndex]))
                {
                    dp[index] = max(dp[index],1+dp[previndex]);
                }
            }

            maxi = max(maxi,dp[index]);
        }

        return maxi;
    }
};
