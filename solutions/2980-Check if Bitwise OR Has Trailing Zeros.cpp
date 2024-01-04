class Solution {
public:
    //Time Complexity :O(n * n) && Space Complexity :O(1)
    // bool hasTrailingZeros(vector<int>& nums) {
    //     int n = nums.size();
        
    //     for(int i=0;i<n;i++)
    //     {
    //         for(int j=i+1;j<n;j++)
    //         {
    //             int orOp = nums[i]  | nums[j];
                
    //             if(orOp % 2 == 0)
    //             {
    //                 return true;
    //             }
    //         }
    //     }
        
    //     return false;
    // }

    //Time Complexity :O(n) && Space Complexity :O(1)
    bool hasTrailingZeros(vector<int>& nums) {
        int n = nums.size();
        
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i] % 2 == 0)
            {
                cnt++;
            }
        }
        
        return (cnt < 2) ? false: true; 
    }
};
