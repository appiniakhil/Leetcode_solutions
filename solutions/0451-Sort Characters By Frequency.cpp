class Solution {
public:
    //Time Complexity :O(nlogn) && Space Complexity :O(n)
    string frequencySort(string s) {
        int n = s.size();
        vector<pair<int, char>> v;
        unordered_map<char, int> mp;

        for(int i=0;i<n;i++)
        {
            mp[s[i]]++;
        }

        for(auto i : mp)
        {
            v.push_back({i.second, i.first});
        }
        
        sort(v.rbegin(), v.rend());
        
        string ans = "";
        
        for(auto i: v)
        {
            for(int j=0;j<i.first;j++)
            {
                ans += i.second;
            }
        }
        
        return ans;
    }
};
