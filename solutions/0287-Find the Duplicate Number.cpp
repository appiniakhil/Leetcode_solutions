class Solution {
public:

    //Here we modified the array nums
    //Time Complexity :O(nlog n) && Space Complexity :O(1)
    // int findDuplicate(vector<int>& nums) {
    //     int n = nums.size();

    //     sort(nums.begin(),nums.end());

    //     for(int i=0;i<n;i++)
    //     {
    //         if(nums[i] == nums[i+1])
    //         {
    //             return nums[i];
    //         }
    //     }

    //     return 0;
    // }

    //Naive Approach
    //Time Complexity :O(n * n) && Space Complexity :O(1)
    // int findDuplicate(vector<int>& nums) {
    //     int n = nums.size();

    //     for(int i=0;i<n;i++)
    //     {
    //         for(int j=i+1;j<n;j++)
    //         {
    //             if(nums[i] == nums[j])
    //             {
    //                 return nums[i];
    //             }
    //         }
    //     }

    //     return 0;
    // }

    //Time Complexity :O(n * n) && Space Complexity : O(1)
    // int findDuplicate(vector<int>& nums) {
    //     int n = nums.size();

    //     for(int i=0;i<n;i++)
    //     {
    //         for(int j=i+1;j<n;j++)
    //         {
    //             if(nums[i] == nums[j])
    //             {
    //                 return nums[i];
    //             }
    //         }
    //     }

    //     return 0;
    // }

    //Binary Search
    //Time Complexity :O(log n) && Space Complexity :O(1)
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();

        int left = 1;
        int right = n-1;
        
        while(left <= right)
        {
            int mid = left + (right-left)/2;
            int count = 0;

            for(auto num: nums)
            {
                if(num<=mid)
                {
                    count++;
                }
            }

            if(count <= mid)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }

        }

        return left;
    }
};
