class Solution {
public:

    //Time Complexity :O(n) && Space Complexity :O(1)
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int p1 = nums[0];
        int p2 = nums[0];
        int ans = nums[0];

        for(int i=1;i<n;i++)
        {
            int temp = max(nums[i],max(p1 * nums[i],p2 * nums[i]));
            p2 = min(nums[i],min(p1 * nums[i],p2 * nums[i]));
            p1 = temp;

            ans = max(ans, p1);
        }

        return ans;
    }
};
