class Solution {
public:
    void reverseArray(vector<int>&nums,int i,int j)
    {
        while(i<j)
        {
            swap(nums[i++],nums[j--]);
        }
    }
    void rotate(vector<int>& nums, int k) {
        //Naive Approach
        //Time Complexity :O(n^2)
        //Time Limit Exceeded
        // for(int i =1;i<=k;i++)
        // {
        //     int temp = nums[0];
        //     for(int j=1;j<nums.size();j++)
        //     {
        //         int temp1 = nums[j];
        //         nums[j] = temp;
        //         temp = temp1;
        //     }
        //     nums[0] = temp;
        // }

        //Optimised Approach
        //Time Complexity :O(n)
        int n=nums.size();
        k=k%n;
        reverseArray(nums,0,n-k-1);
        reverseArray(nums,n-k,n-1);
        reverseArray(nums,0,n-1);

    }
};
