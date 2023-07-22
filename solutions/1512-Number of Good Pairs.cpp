class Solution {
public:

    //Naive Approach
    //Time Complexity :O(n * n) && Space Complexity :O(1)
    // int numIdenticalPairs(vector<int>& nums) {
    //     int n = nums.size();

    //     int count = 0;
    //     for(int i=0;i<n;i++)
    //     {
    //         for(int j=i+1;j<n;j++)
    //         {
    //             if(nums[i] == nums[j])
    //             {
    //                 count++;
    //             }
    //         }
    //     }
        
    //     return count;
    // }

    //Time Complexity :O(n) && Space Complexity :O(n)
    int numIdenticalPairs(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int,int> mp;

        int count=0;
        for(int i=0;i<n;i++){
           
            count += mp[nums[i]];
         
            mp[nums[i]]++;
        }

        return count;
    }
};
