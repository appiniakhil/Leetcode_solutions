class Solution {
public:

    //Time Complexity :O(nlogn + 2n) && Space Complexity :O(n)
    // vector<vector<int>> merge(vector<vector<int>>& intervals) {
    //     int n = intervals.size();
    //     sort(intervals.begin(), intervals.end());

    //     vector<vector<int>> ans;
    //     for(int i=0;i<n;i++)
    //     {
    //         int start = intervals[i][0];
    //         int end = intervals[i][1];

    //         if(!ans.empty() && end <= ans.back()[1])
    //         {
    //             continue;
    //         }

    //         for(int j=i+1;j<n;j++)
    //         {
    //             if(intervals[j][0] <= end)
    //             {
    //                 end = max(intervals[j][1], end);
    //             }
    //             else
    //             {
    //                 break;
    //             }
    //         }
    //         ans.push_back({start, end});
    //     }

    //     return ans;
    // }

    //Time Complexity :O(nlogn + n) && Space Complexity :O(n)
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> ans;
        for(int i=0;i<n;i++)
        {
            if(ans.empty() || ans.back()[1] < intervals[i][0])
            {
                ans.push_back(intervals[i]);
            }
            else
            {
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);
            }
        }

        return ans;
    }

};
