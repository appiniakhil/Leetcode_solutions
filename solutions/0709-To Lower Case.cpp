class Solution {
public:
    //Time Complexity :O(n) && Space Complexity :O(n)
    string toLowerCase(string s) {
        string ans ="";
        for(int i=0;i<s.length();i++)
        {
            ans += tolower(s[i]);
        }

        return ans;
    }
};
