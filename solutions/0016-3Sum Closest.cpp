class Solution {
public:

    //Two pointers
    //Time Complexity :O(n * n) && Space Complexity :O(1)
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();

        sort(nums.begin(),nums.end());
        int ans = nums[0] + nums[1] + nums[2];
        int mini = INT_MAX;
        for(int i=0;i<n;i++)
        {
            int j=i+1;
            int k=n-1;

            while(j < k)
            {
                int sum = nums[i] + nums[j] + nums[k];
                if(sum == target)
                {
                    return sum;
                }
                else if(sum < target)
                {
                    j++;
                }
                else
                {
                    k--;
                }
                
                if(abs(sum - target) < abs(ans - target))
                {
                    ans = sum;
                }
            }
        }

        return ans;
    }
};
