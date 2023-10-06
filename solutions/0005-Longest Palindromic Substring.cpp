class Solution {
public:
    //Time Complexity :O(n * n) && Space Complexity ;O(n * n)
    string longestPalindrome(string s) {
        int n = s.length();
        
        if (n <= 1) 
        {
            return s;
        }
        
        vector<vector<bool>> isPalindrome(n, vector<bool>(n, false));
        int start = 0; 
        int maxLength = 1;
        
        // All substrings of length 1 are palindromes.
        for(int i=0;i<n;i++) 
        {
            isPalindrome[i][i] = true;
        }
        
        // Check for palindromes of length 2.
        for (int i=0;i<n-1;i++) 
        {
            if (s[i] == s[i + 1]) 
            {
                isPalindrome[i][i + 1] = true;
                start = i;
                maxLength = 2;
            }
        }
        
        // Check for palindromes of length 3 or more.
        for (int len=3;len<=n;len++) 
        {
            for(int i=0;i<n-len+1;i++) 
            {
                int j = i + len - 1; 
                
                if (s[i] == s[j] && isPalindrome[i + 1][j - 1]) 
                {
                    isPalindrome[i][j] = true;
                    
                    if (len > maxLength)
                    {
                        start = i;
                        maxLength = len;
                    }
                }
            }
        }
        
        return s.substr(start, maxLength);
    }
};
