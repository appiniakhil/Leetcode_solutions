class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        //Naive Approach
        //Time Compexity :O(n^2)
        // int maxi = INT_MIN;  
        // int count = 0; 
        // int i = 0; 
        // int n = nums.size();
        // while(i < n) 
        // {  
        //     count = 0; 
        //     while(i < n && nums[i] != 1) 
        //     {
        //         i++;
        //     }  
        //     while(i < n && nums[i] == 1) 
        //     { 
        //         i++; 
        //         count++;
        //     }  
        //     maxi = max(count,maxi);
        // }  
        // return maxi;
        
        
        //Optimised Approach
        //Time Complexity:O(n)
        int maxi = 0;
        int count = 0;
        int n = nums.size();
        for(int i =0;i<n;i++)
        {
            if(nums[i] == 1)
            {
                count++;
                maxi = max(maxi,count);
            }
            else
            {
                count = 0;
            }
        }
        return maxi;
    }
};
