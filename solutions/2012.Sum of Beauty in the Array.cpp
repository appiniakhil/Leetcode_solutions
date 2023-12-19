class Solution {
public:
    //Time Complexity :O(n) && Space Complexity :O(n)
    int sumOfBeauties(vector<int>& nums) {
        int n = nums.size();

        vector<int> maxiL(n), miniR(n);

        maxiL[0] = nums[0];
        for(int i=1;i<n;i++) 
        {
            maxiL[i] = max(maxiL[i-1], nums[i]);
        }

        miniR[n-1] = nums[n-1];
        for(int i=n-2;i>=0;i--) 
        {
            miniR[i] = min(miniR[i+1], nums[i]);
        }

        int sum = 0;
        for(int i=1;i<n-1;i++) 
        {
            if(nums[i] > maxiL[i-1] && nums[i] < miniR[i+1]) 
            {
                sum += 2;
            } 
            else if(nums[i] > nums[i-1] && nums[i] < nums[i+1]) 
            {
                sum += 1;
            }
        }
        return sum;
    }
};
