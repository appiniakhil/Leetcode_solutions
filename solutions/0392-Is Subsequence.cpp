class Solution {
public:

    //Using Two pointers
    //Time Complexity : O(n + m) && Space Complexity :O(1)
    bool isSubsequence(string s, string t) {
        
        int firstptr = 0;
        int secondptr = 0;

        while(secondptr < t.size() && firstptr < s.size())
        {
            if(s[firstptr] == t[secondptr])
            {
                firstptr++;
                secondptr++;
            }
            else
            {
                secondptr++;
            }
        }

        return firstptr == s.length();
    }
};
