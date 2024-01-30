class Solution {
public:
    //Time Complexity :O(n) && Space Complexity :O(n)
    bool isOperator(string &op)
    {
        return op.size() == 1 && string("+-*/").find(op) != string::npos;
    }

    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for(string& token : tokens)
        {
            if(isOperator(token))
            {
                int op2 = st.top();
                st.pop();

                int op1 = st.top();
                st.pop();

                switch(token[0])
                {
                    case '+':
                        st.push(op1 + op2);
                        break;
                    case '-':
                        st.push(op1 - op2);
                        break;
                    case '*':
                        st.push(op1 * op2);
                        break;
                    case '/':
                        st.push(op1 / op2);
                        break;
                }
            }
            else
            {
                st.push(stoi(token));
            }
        }

        return st.top();
    }
};
