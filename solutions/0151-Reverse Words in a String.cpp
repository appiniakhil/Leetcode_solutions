class Solution {
public:
    //Time Complexity :O(n) && Space Complexity :O(n)
    string reverseWords(string s) {
        int n = s.length();
        string ans = "";

        for(int i = n - 1; i >= 0; i--) 
        {
            if(s[i] == ' ')
            {
                continue;
            }

            string temp = "";

            while(i >= 0 && s[i] != ' ') 
            {
                temp += s[i];
                i--;
            }

            reverse(temp.begin(), temp.end());
            ans += temp;

            if(i >= 0) 
            {
                ans += ' ';
            }
        }

        int si = ans.size();
        if(ans[si-1] == ' ')
        {
            return ans.substr(0, si-1);
        }
        
        return ans;
    }
};
