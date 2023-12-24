class Solution {
public:
    //Time Complexity :O(n) && Space Complexity :O(1)
    int minOperations(string s) {
        int n = s.size();

        int cnt=0, cnt1=0;

        for(int i=0;i<n;i++)
        {
            if(s[i] != '0' + i%2)
            {
                cnt++;
            }
        }

        for(int i=0;i<n;i++)
        {
            if(s[i] != '0' + (i+1)%2)
            {
                cnt1++;
            }
        }

        return min(cnt, cnt1);
    }
};
