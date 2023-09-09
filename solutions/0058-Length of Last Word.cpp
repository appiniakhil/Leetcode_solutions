class Solution {
public:
    //Time Complexity :O(n) && Space Complexity :O(n)
    int lengthOfLastWord(string s) {
        int n = s.size();

        string ans ="";
        int i = 0;

        for(int j=0;j<n;j++)
        {
            if(s[n-j-1] != ' ')
            {
                break;
            }
            i++;
        }
        
        while(i < n)
        {
            if(s[n-i-1] == ' ')
            {
                break;
            }
            ans += s[n-i-1]; 
            i++;
        }

        return ans.size();
    }
};
