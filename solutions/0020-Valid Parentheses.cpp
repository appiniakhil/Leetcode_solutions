class Solution {
public:
    //Time Complexity :O(n) && Space Complexity :O(n)
    bool isValid(string s) {
        stack<char> st;

        for(char c : s)
        {
            if(c == '(' || c == '{' || c == '[')
            {
                st.push(c);
            }
            else
            {
                if(st.empty())
                {
                    return false;
                }

                char openBrack = st.top();
                st.pop();

                if ((c == ')' && openBrack != '(') || (c == ']' && openBrack != '[') || (c == '}' && openBrack != '{')) 
                {
                    return false; 
                }
            }
        }

        return st.empty();
    }
};
