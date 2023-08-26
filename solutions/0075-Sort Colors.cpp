class Solution {
public:
    //Naive Approach
    //Inbuilt Function
    //Time Complexity :O(nlogn) && Space Complexity :O(1)
    // void sortColors(vector<int>& nums) {
    //     sort(nums.begin(), nums.end());
    // }

    //Time Complexity :O(n * n) && Space Complexity :O(1)
    // void sortColors(vector<int>& nums) {
    //     int n = nums.size();

    //     for(int i=0;i<n;i++)
    //     {
    //         for(int j=i+1;j<n;j++)
    //         {
    //             if(nums[i] > nums[j])
    //             {
    //                 swap(nums[i], nums[j]);
    //             }
    //         }
    //     }

    // }

    //The Dutch National Flag Problem
    //Time Complexity :O(n) && Space Complexity :O(1)
    void sortColors(vector<int>& nums) {
        int n = nums.size();

        int l=0,r=n-1,mid=0;
        while(r >= mid)
        {
            switch(nums[mid])
            {
                case 0:
                    swap(nums[l], nums[mid]);
                    mid++;
                    l++;
                    break;
                case 1:
                    mid++;
                    break;
                case 2:
                    swap(nums[mid], nums[r]);
                    r--;
                    break;
            }
        }
    }
};
