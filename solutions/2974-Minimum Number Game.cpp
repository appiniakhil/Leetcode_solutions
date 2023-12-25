class Solution {
public:
    //Time Complexity :O(n) && Space Complexity :O(n)
    vector<int> numberGame(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        
        vector<int> ans;
        
        int i=0,j=1;
        while(i <n || j< n)
        {
            ans.push_back(nums[j]);
            ans.push_back(nums[i]);
            i+=2;
            j+=2;
        }
            
        return ans;
    }
};
