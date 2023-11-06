class Solution {
public:
    //Time Complexity :O(n) && Space Complexity :O(n)
    string removeStars(string s) {
        int n = s.length();

        stack<char> st;

        for(int i=0;i<n;i++)
        {
            if(s[i] != '*')
            {
                st.push(s[i]);
            }
            else
            {
                if(!st.empty())
                {
                    st.pop();
                }
            }
        }

        string ans ="";

        while(!st.empty())
        {
            ans += st.top();
            st.pop();
        }

        reverse(ans.begin(),ans.end());

        return ans;
    }
};
