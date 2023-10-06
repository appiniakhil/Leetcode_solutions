class Solution {
public:
    //Time Complexity :O(n) && Space Complexity :O(1)
    int myAtoi(string s) {
        int n = s.length();

        int sign = 1;
        int res = 0;

        int i=0;

        while(i<n && s[i] == ' ')
        {
            i++;
        }

        if(i<n && (s[i] == '+' || s[i] == '-'))
        {
            if(s[i] == '-')
            {
                sign = -1;
            }
            else
            {
                sign = 1;
            }
            i++;
        }

        while(i < n && isdigit(s[i]))
        {
            int dig = s[i] - '0';

            // Check for overflow
            if (res > INT_MAX / 10 || (res == INT_MAX / 10 && dig > 7)) {
                return (sign == 1) ? INT_MAX : INT_MIN;
            }

            res = res*10 + dig;
            i++;
        }

        res *= sign;

        return res;
    }
};
