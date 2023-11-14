class Solution {
public:
    //Time Complexity :O(n) && Space Complexity :O(1)
    int countPalindromicSubsequence(string s) {
        int n = s.size();

        vector<int> first(26, INT_MAX), last(26, INT_MIN);
        
        for(int i=0;i<n;i++)
        {
            first[s[i] - 'a'] = min(first[s[i] -'a'], i);

            last[s[i] - 'a'] = max(last[s[i] - 'a'], i);
        }

        int cnt = 0;
        for(int i=0;i<26;i++)
        {
            if(first[i] < last[i])
            {
                set<char> uniq(s.begin() + first[i] + 1, s.begin() + last[i]);
                
                cnt += uniq.size();
            }
        }

        return cnt;
    }
};
