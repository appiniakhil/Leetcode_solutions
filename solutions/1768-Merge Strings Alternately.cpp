class Solution {
public:
    //Two Pointer Approach
    //Time Complexity :O(n + m) && Space Complexity :O(n + m)
    string mergeAlternately(string word1, string word2) {
        int i =0,j=0;
        int n = word1.size();
        int m = word2.size();

        string ans = "";
        while(i<n && j<m)
        {
            ans += word1[i];
            ans += word2[j];
            i++;
            j++;
        }

        for(;i<n;i++)
        {
            ans += word1[i];
        }

        for(;j<m;j++)
        {
            ans += word2[j];
        }

        return ans;
    }
};
