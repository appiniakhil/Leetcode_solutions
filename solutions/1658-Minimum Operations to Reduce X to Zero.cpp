class Solution {
public:
    //Time Complexity :O(n) && Space Complexity :O(1)
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        
        int totsum = 0;
        for(int i=0;i<n;i++)
        {
            totsum += nums[i];
        }
        
        int target = totsum - x;

        if(target == 0)
        {
            return n;
        }
        
        int j = 0;
        int sum = 0;
        int mini = INT_MAX;
        for(int i=0;i<n;i++)
        {
            sum += nums[i];
            
            while(sum > target && j <= i)
            {
                sum -= nums[j];
                j++;
            }

            if(sum == target)
            {
                mini = min(mini, (n-1-i) + j);
            }
        }

        if(mini != INT_MAX)
        {
            return mini;
        }

        return -1;
    }
};
