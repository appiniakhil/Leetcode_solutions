class Solution {
public:
    //Time Complexity :O(n) && Space Complexity :O(1)
    string smallestString(string s) {
        for(int i=0;i<s.size();i++)
        {
            if(s[i] != 'a')
            {
                while(i < s.size() && s[i] != 'a')
                {
                    s[i] = s[i] - 1;
                    i++;
                }

                break;
            }

            if(i == s.size() - 1 && s[i] == 'a') 
            {
                s[i] = 'z';
            }
        }

        return s;
    }
};
