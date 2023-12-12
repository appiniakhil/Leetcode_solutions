class Solution {
public:
    //Time Complexity :O(nlogn) && Space Complexity :O(1)
    // int maxProduct(vector<int>& nums) {
    //     int n = nums.size();
    //     sort(nums.begin(), nums.end());

    //     return (nums[n-1]-1)*(nums[n-2]-1);
    // }

    //Time Complexity :O(n) && Space Complexity :O(1)
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int maxi1 = INT_MIN, maxi2 = INT_MIN, ind = 0;

        for(int i=0;i<n;i++)
        {
            if(nums[i] > maxi1)
            {
                maxi1 = nums[i];
                ind = i;
            }
        }

        nums[ind] = 0;
        for(int i=0;i<n;i++)
        {
            if(nums[i] > maxi2)
            {
                maxi2 = nums[i];
            }
        }

        return (maxi1-1)*(maxi2-1);
    }
};
