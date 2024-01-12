class Solution {
public:
    //Time Complexity :O(n) && Space Complexity :O(n)
    int vow(string s)
    {
        int n = s.size();
        int cnt = 0;

        for(int i=0;i<n;i++)
        {
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U')
            {
                cnt++;
            }
        }

        return cnt;
    }

    bool halvesAreAlike(string s) {
        int n = s.size();
        string s1 = "";
        string s2 = "";

        for(int i=0;i<n/2;i++)
        {
            s1 += s[i];
        }

        for(int i=n/2;i<n;i++)
        {
            s2 += s[i];
        }

        if(vow(s1) == vow(s2))
        {
            return true;
        }

        return false;
    }
};
