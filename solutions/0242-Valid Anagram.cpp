class Solution {
public:

    //Time Complexity :O(nlogn  + mlogm) && Space Complexity :O(1)
    // bool isAnagram(string s, string t) {
    //     sort(s.begin(), s.end());
    //     sort(t.begin(), t.end());

    //     if(s == t)
    //     {
    //         return true;
    //     }

    //     return false;
    // }

    //Using Map
    //Time Complexity :O(n + m) && Space Complexity :O(min(n,m))
    bool isAnagram(string s, string t) {
        int n = s.size();
        int m = t.size();

        if(n != m)
        {
            return false;
        }

        unordered_map<char,int> mp;
        for(int i=0;i<n;i++)
        {
            mp[s[i]]++;
            mp[t[i]]--;
        }

        for(auto x: mp)
        {
            if(x.second != 0)
            {
                return false;
            }
        }

        return true;
    }
};
