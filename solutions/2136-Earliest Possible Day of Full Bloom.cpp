class Solution {
private:
    //Time Complexity :O(nlogn) && Space Complexity :O(n)
    static bool comparator(const pair<int, int>& a, const pair<int, int>& b)
    {
        return a.second > b.second;
    }

public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        int n = plantTime.size();

        vector<pair<int, int>> seeds;

        for(int i=0;i<n;i++)
        {
            seeds.push_back({plantTime[i], growTime[i]});
        }

        sort(seeds.begin(), seeds.end(), comparator);

        int day = 0;
        int maxDay = 0;

        for(int i=0;i<n;i++)
        {
            day += seeds[i].first;
            maxDay = max(maxDay, day + seeds[i].second);
        }

        return maxDay;
    }
};
