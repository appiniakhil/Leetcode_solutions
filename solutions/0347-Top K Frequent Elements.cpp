class Solution {
public:
    //Time Complexity :O(nlogk) && Space Complexity :O(n + k)
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;

        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        for(auto& i : mp)
        {
            pq.push({i.second, i.first});

            if(pq.size() > k)
            {
                pq.pop();
            }
        }

        vector<int> ans;
        while(!pq.empty())
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};
