class Solution {
public:
    //Time Complexity :O(n) && Space Complexity :O(n)
    string finalS(string s)
    {
        stack<char> st;
        for(int i=0;i<s.length();i++)
        {
            if(s[i] != '#')
            {
                st.push(s[i]);
            }
            else if(!st.empty())
            {
                st.pop();
            }
        }

        string ans = "";
        while(!st.empty())
        {
            ans += st.top();
            st.pop();
        }

        return ans;
    }

    bool backspaceCompare(string s, string t) {
        string s1 = finalS(s);
        string s2 = finalS(t);

        return (s1 == s2);
        
    }
};
