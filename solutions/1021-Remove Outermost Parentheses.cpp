class Solution {
public:
    //Time Complexity :O(n) && Space Complexity :O(n)
    string removeOuterParentheses(string s) {
        
        string ans = "";
        int i=0;
        int cnt = 0;
        for(char i: s)
        {
            if(i == '(' && cnt == 0)
            {
                cnt++;
            }
            else if(i == '(' && cnt >= 1)
            {
                ans += i;
                cnt++;
            }
            else if(i == ')' && cnt > 1)
            {
                ans += i;
                cnt--;
            }
            else if(i == ')' && cnt == 1)
            {
                cnt--;
            }
        }

        return ans;
    }
};
