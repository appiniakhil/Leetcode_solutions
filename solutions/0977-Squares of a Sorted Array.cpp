class Solution {
public:
    //Time Complexitu : O(nlogn) && Space Complexity :O(n)
    // vector<int> sortedSquares(vector<int>& nums) {
    //     int n = nums.size();

    //     vector<int> ans;
    //     for(int i=0;i<n;i++)
    //     {
    //         ans.push_back(nums[i] * nums[i]);
    //     }

    //     sort(ans.begin(),ans.end());

    //     return ans;
    // }

    //Time Complexitu : O(nlogn) && Space Complexity :O(n)
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();

        
        for(int i=0;i<n;i++)
        {
            int temp = nums[i] * nums[i];
            nums[i] = temp;
        }

        sort(nums.begin(),nums.end());

        return nums;
    }
};
