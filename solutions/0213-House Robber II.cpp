class Solution {
public:
    //We are using same logic as problem number 198 and the only difference is first and last elemnt cannot be in same subarray.
    //So we will split the array into two and finding maximum between them.
    
    int helper(vector<int>& nums) {
        //Space Optimisation
        //Time Complexity :O(n) && Space Complexity :O(1)
        int n = nums.size();
        int prev = nums[0];
        int prev2 = 0;
        for(int i =1;i<n;i++)
        {
            int pick = nums[i];
            if(i>1) 
                pick += prev2;
            int notpick = prev;
            int curi = max(pick, notpick);
            prev2 = prev;
            prev = curi;
        }
        return prev;
    }

    int rob(vector<int>& nums) {

        vector<int> temp1, temp2;
        int n = nums.size();
        if(n == 1) return nums[0];
        for(int i =0;i<n;i++)
        {
            if(i != 0) temp1.push_back(nums[i]);
            if(i != n-1) temp2.push_back(nums[i]);
        }
        
        return max(helper(temp1), helper(temp2));
    }
};
