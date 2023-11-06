class Solution {
public:
    //Time Complexity :O(n) && Space Complexity :O(1)
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        int l=0;
        double ans=0,curr=0,maxi=INT_MIN;

        for(int r=0;r<n;r++)
        {
            curr = nums[r];

            ans += nums[r];
            if(r-l+1>k)
            {
                ans -= nums[l];
                l++;
            }

            if(r-l+1 == k)
            {
                maxi = max(maxi, ans/k);
            }
        }

        return maxi;
    }
};
