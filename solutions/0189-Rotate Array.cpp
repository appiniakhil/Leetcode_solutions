class Solution {
public:
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
    }
};
