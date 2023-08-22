class Solution {
public:
    //Time Complexity :O(n * n) && Space Complexity :O(n)
    // string helper(string s)
    // {
    //     int n = s.length();

    //     string ans = "";
    //     for(int i=n-1;i>=0;i--)
    //     {
    //         ans += s[i];
    //     }
    //     return ans;
    // }

    // string finalString(string s) {
    //     int n = s.length();

    //     string ans = "";
    //     for(int i=0;i<n;i++)
    //     {
    //         if(s[i] == 'i')
    //         {
    //             ans = helper(ans);
    //         }
    //         else
    //         {
    //             ans += s[i];
    //         }
    //     }

    //     return ans;
    // }

    //Using builtin function
    string finalString(string s) {
        int n = s.length();

        string ans = "";
        for(int i=0;i<n;i++)
        {
            if(s[i] == 'i')
            {
                reverse(ans.begin(), ans.end());
            }
            else
            {
                ans += s[i];
            }
        }

        return ans;
    }
};
