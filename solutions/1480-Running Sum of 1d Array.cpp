class Solution {
public:
    //Time Complexity :O(n) && Space Complexity :O(n)
    // vector<int> runningSum(vector<int>& nums) {
    //     int n = nums.size();

    //     vector<int> temp;
    //     int sum = 0;
    //     for(int i=0;i<n;i++)
    //     {
    //         sum += nums[i];
    //         temp.push_back(sum);
    //     }

    //     return temp;
    // }

    //Time Complexity :O(n) && Space Complexity :O(1)
    vector<int> runningSum(vector<int>& nums) {
        int n = nums.size();

        for(int i=1;i<n;i++)
        {
            nums[i] += nums[i-1];
        }

        return nums;
    }
};
