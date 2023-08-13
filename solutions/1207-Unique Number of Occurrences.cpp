class Solution {
public:
    //Time Complexity :O(n) && Space Complexity :O(k) where k is the number of unique elements
    bool uniqueOccurrences(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int> mp;
        for(int i=0;i<n;i++)
        {
            mp[arr[i]]++;
        }

        unordered_map<int, int> Countmp;
        for(auto& it : mp)
        {
            Countmp[it.second]++;
        }

        return mp.size() == Countmp.size();
    }
};
