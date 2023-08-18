class Solution {
public:
    //Time Complexity :O(n) && Space Complexity :O(1)
    int balancedStringSplit(string s) {
        int n = s.size();
        int ans = 0;
        int cnt1= 0;
        int cnt2 = 0;

        for(int i=0;i<n;i++)
        {
            if(s[i] == 'R')
            {
                cnt2++;
            }
            else
            {
                cnt1++;
            }

            if(cnt1 == cnt2)
            {
                ans++;
                cnt1=0;
                cnt2=-0;
            }
        }

        return ans;
    }
};

