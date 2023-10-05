class Solution {
public:
    //Time Complexity :O(n) && Space Complexity :O(1)
    string decodeAtIndex(string s, int k) {
        long size = 0;
        int i = 0;

        while(size < k)
        {
            if(isdigit(s[i]))
            {
                size *= (s[i] - '0');
            }
            else
            {
                size++;
            }
            i++;
        }

        while(i--)
        {
            if(isdigit(s[i]))
            {
                size /= (s[i] - '0');
                k %= size;
            }
            else if(k == 0 || k == size)
            {
                return string(1, s[i]);
            }
            else
            {
                size--;
            }
        }

        return "";
    }
};
