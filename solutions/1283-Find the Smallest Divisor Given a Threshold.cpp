class Solution {
public:

    //Time Limit Exceeded
    //Time Complexity : O(maxi * n) && Space Complexity :O(1)
    // int helper(vector<int>& nums,int ind)
    // {
    //     int n = nums.size();
    //     int sum = 0;
    //     for(int i=0;i<n;i++)
    //     {
    //         sum += ceil((double)(nums[i])/(double)(ind));
    //     }

    //     return sum;
    // }

    // int smallestDivisor(vector<int>& nums, int threshold) {
    //     int n = nums.size();
    //     int maxi = *max_element(nums.begin(), nums.end());

    //     for(int i=1;i<=maxi;i++)
    //     {
    //         if(helper(nums,i) <= threshold)
    //         {
    //             return i;
    //         }
    //     }

    //     return -1;
    // }

    //Time Complexity : O(log(maxi * n)) && Space Complexity :O(1)
    int helper(vector<int>& nums,int ind)
    {
        int n = nums.size();
        int sum = 0;
        for(int i=0;i<n;i++)
        {
            sum += ceil((double)(nums[i])/(double)(ind));
        }

        return sum;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();

        if(n > threshold)
        {
            return -1;
        }

        int maxi = *max_element(nums.begin(), nums.end());

        int low = 1,high = maxi;

        while(low <= high)
        {
            int mid = low + (high-low)/2;
            if(helper(nums,mid) <= threshold)
            {
                high = mid-1;
            }
            else
            {
                low = mid+1;
            }
        }

        return low;
    }
};
