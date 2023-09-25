class Solution {
public:
    //Time Complexity :O(n) && Space Complexity :O(1)
    char findTheDifference(string s, string t) {
        char ans = 0; 
        int i = 0;
        int n = s.size();
        int m = t.size();

        while(i < n)
        {
            ans ^= s[i]; 
            ans ^= t[i]; 
            i++;
        }

        ans ^= t[i];

        return ans;

    }
};
