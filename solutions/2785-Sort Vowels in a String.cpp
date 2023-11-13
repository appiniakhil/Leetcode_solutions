class Solution {
public:
    //Time Complexity :O(nlogn) && Space Complexity :O(n)
    bool isVowel(char s)
    {
        if(s == 'a' || s == 'e' || s == 'i' || s == 'o' || s == 'u' || s == 'A' || s == 'E' || s == 'I' || s == 'O' || s == 'U')
        {
            return true;
        }

        return false;
    }
    
    string sortVowels(string s) {
        int n = s.length();

        string vow = "";

        for(int i=0;i<n;i++)
        {
            if(isVowel(s[i]))
            {
                vow += s[i];
            }
        }

        sort(vow.begin(), vow.end());
        int j = 0;

        for(int i=0;i<n;i++)
        {
            if(isVowel(s[i]))
            {
                if(j < n)
                {
                    s[i] = vow[j];
                    j++;
                }
            }
        }

        return s;
    }
};
