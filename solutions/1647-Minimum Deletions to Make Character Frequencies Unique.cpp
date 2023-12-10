class Solution {
public:
    //Time Complexity :O(nlogn) && Space Complexity: O(n)
    int minDeletions(string s) {
        unordered_map<char, int> mp;

        for (char c : s) {
            mp[c]++;
        }

        vector<int> freq;

        for(auto& [_, f] : mp) 
        {
            freq.push_back(f);
        }

        sort(freq.begin(), freq.end(), greater<int>());

        int res = 0;

        for(int i=1;i<freq.size();++i) 
        {
            while(freq[i]>0 && freq[i]>=freq[i - 1]) 
            {
                freq[i]--;
                res++;
            }
        }

        return res;
    }
};
