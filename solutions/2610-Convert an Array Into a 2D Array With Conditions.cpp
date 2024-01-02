class Solution {
public:
    //Time Complexity :O(n) && Space Complexity :O(n)
    vector<vector<int>> findMatrix(vector<int>& nums) {
        map<int, int> mp;

        for(int i : nums)
        {
            mp[i]++;
        }

        vector<vector<int>> ans;

        while(!mp.empty())
        {
            vector<int> row;

            for(auto i = mp.begin();i != mp.end();)
            {
                row.push_back(i->first);

                if(--i->second == 0)
                {
                    i = mp.erase(i);
                }
                else
                {
                    ++i;
                }
            }

            ans.push_back(row);
        }

        return ans;
    }
};
