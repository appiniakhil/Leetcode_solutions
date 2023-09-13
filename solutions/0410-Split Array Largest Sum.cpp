class Solution {
public:
    //Time Limit Exceeded
    //Time Complexity: O(n * (sum-maxi+1)) && Space Complexity :O(1)
    // int helper(vector<int>& nums, int val)
    // {
    //     int totalSubarray = 1;
    //     int totalSum = 0;
    //     int n = nums.size();

    //     for(int i=0;i<n;i++)
    //     {
    //         if(totalSum + nums[i] <= val)
    //         {
    //             totalSum += nums[i];
    //         }
    //         else
    //         {
    //             totalSum = nums[i];
    //             totalSubarray++;
    //         }
    //     }

    //     return totalSubarray;
    // }

    // int splitArray(vector<int>& nums, int k) {
    //     int n = nums.size();
    //     int maxi = INT_MIN;
    //     int sum = 0;

    //     if(k > n)
    //     {
    //         return -1;
    //     }

    //     for(int i=0;i<n;i++)
    //     {
    //         maxi = max(maxi, nums[i]);
    //         sum += nums[i];
    //     }

    //     for(int i=maxi;i<=sum;i++)
    //     {
    //         if(helper(nums, i) == k)
    //         {
    //             return i;
    //         }
    //     }

    //     return maxi;
    // }

    //Time Complexity: O(log(n * (sum-maxi+1))) && Space Complexity :O(1)
    int helper(vector<int>& nums, int val)
    {
        int totalSubarray = 1;
        int totalSum = 0;
        int n = nums.size();

        for(int i=0;i<n;i++)
        {
            if(totalSum + nums[i] <= val)
            {
                totalSum += nums[i];
            }
            else
            {
                totalSum = nums[i];
                totalSubarray++;
            }
        }

        return totalSubarray;
    }

    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        int maxi = INT_MIN;
        int sum = 0;

        if(k > n)
        {
            return -1;
        }

        for(int i=0;i<n;i++)
        {
            maxi = max(maxi, nums[i]);
            sum += nums[i];
        }

        int low = maxi, high = sum;

        while(low <= high)
        {
            int mid = low + (high-low)/2;
            if(helper(nums,mid) > k)
            {
                low = mid+1;
            }
            else
            {
                high = mid-1;
            }
        }

        return low;
    }
};
