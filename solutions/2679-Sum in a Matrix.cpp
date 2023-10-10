class Solution {
public:
    //Time Complexity :O(n * m * logm) && Space Complexity :O(1)
    // int matrixSum(vector<vector<int>>& nums) {
    //     int n = nums.size();
    //     int m = nums[0].size();

    //     for(int i=0;i<n;i++)
    //     {
    //         sort(nums[i].begin(), nums[i].end());
    //     }

    //     int score = 0;
    //     for(int i=0;i<m;i++)
    //     {
    //         int maxi = 0;
    //         for(int j=0;j<n;j++)
    //         {
    //             maxi = max(maxi, nums[j][i]);
    //         }
    //         score += maxi;
    //     }

    //     return score;
    // }

    //Time Complexity :O(n * m * logm) && Space Complexity :O(1)
    int matrixSum(vector<vector<int>>& nums) {
        int n = nums.size();
        int m = nums[0].size();

        vector<int> columnMax(m, INT_MIN);

        for(int i = 0;i<n;i++) 
        {
            sort(nums[i].begin(), nums[i].end());
            for (int j=0;j<m;j++) 
            {
                columnMax[j] = max(columnMax[j], nums[i][j]);
            }
        }

        int score = 0;
        for (int j=0;j<m;j++) 
        {
            score += columnMax[j];
        }

        return score;
    }
};
