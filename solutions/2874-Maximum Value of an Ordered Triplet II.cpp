class Solution {
public:
    //Time Complexity :O(n * n * n) && Space Complexity :O(1)
    // long long maximumTripletValue(vector<int>& nums) {
    //     int n = nums.size();
        
    //     long long maxi = INT_MIN;
    //     for(int i=0;i<n;i++)
    //     {
    //         for(int j=i+1;j<n;j++)
    //         {
    //             for(int k=j+1;k<n;k++)
    //             {
    //                 if(nums[i] - nums[j] > 0)
    //                 {
    //                     maxi = max(maxi, (long long)(nums[i] - nums[j]) * nums[k]);
                        
    //                 }
    //             }
    //         }
    //     }

    //     if(maxi < 0)
    //     {
    //         return 0;
    //     }

    //     return maxi;
    // }

    //Time Complexity :O(n) && Space Complexity :O(1)
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        
        long long maxi = 0;
        long long maxi2 = -1e6;
        long long ans = 0;

        for(int i=0;i<n;i++)
        {
            ans = max(ans, maxi2 * nums[i]);
            maxi2 = max(maxi2, maxi - nums[i]);
            maxi = max(maxi, (long long)nums[i]);
        }

        return ans;
    }
};
