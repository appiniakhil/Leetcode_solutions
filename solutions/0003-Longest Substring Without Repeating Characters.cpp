class Solution {
public:
    //Time Complexity :O(n) && Space Complexity :O(n)
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        vector<int> mp(256, -1);

        int left = 0,right = 0;
        int ans = 0;

        while(right < n)
        {
            if(mp[s[right]] != -1)
            {
                left = max(mp[s[right]] + 1, left);
            }

            mp[s[right]] = right;

            ans = max(ans, right-left+1);
            right++;
        }

        return ans;
    }
};
