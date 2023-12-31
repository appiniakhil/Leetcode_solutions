class Solution {
public:
    //Time Complexity :O(n*n) && Space Complexity :O(n)
    // int maxLengthBetweenEqualCharacters(string s) {
    //     int n=s.size();

    //     int maxi = -1;
    //     for(int i=0;i<n;i++)
    //     {
    //         for(int j=i+1;j<n;j++)
    //         {
    //             if(s[i] == s[j])
    //             {
    //                 maxi = max(maxi, j-i-1);
    //             }
    //         }
    //     }

    //     return maxi;
    // }
    
    //Time Complexity :O(n) && Space Complexity :O(n)
    int maxLengthBetweenEqualCharacters(string s) {
        int n=s.size();

        unordered_map<char, int> mp;
        int maxi = -1;
        for(int i=0;i<n;i++)
        {
            if(mp.find(s[i]) != mp.end())
            {
                maxi = max(maxi, i-mp[s[i]]-1);
            }
            else
            {
                mp[s[i]] = i;
            }
        }

        return maxi;
    }
};
