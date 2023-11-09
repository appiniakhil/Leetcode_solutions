class Solution {
public:
    //Time Complexity :O(n * n) && Space Complexity :O(n)
    bool repeatedSubstringPattern(string s) {
        int n=s.size();

        for(int i=n/2;i>0;i--)
        {
            int rep = n/i;

            string substring = s.substr(0, i);
            string ans="";
            for(int i=0;i<rep;i++)
            {
                ans += substring;
            }

            if(ans == s)
            {
                return true;
            }
        }

        return false;
    }
};
