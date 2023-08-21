class Solution {
public:
    //Time Complexity :O(n) && Space Complexity :O(n)
    string restoreString(string s, vector<int>& indices) {
        int n = s.size();
        string ans = s;

        for(int i=0;i<n;i++)
        {
            ans[indices[i]] = s[i];
        }

        return ans;
    }
};
