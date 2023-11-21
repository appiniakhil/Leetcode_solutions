class Solution {
public:
    //Time Complexity :O(nlogn) && Space Complxity :O(n)
    int distinctAverages(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        unordered_map<long double, long> mp;
        int  i = 0, j = n-1;

        while(i < j)
        {
            long double sum = (long double)(nums[i] + nums[j]) / 2.0; 
            mp[sum]++;
            i++;
            j--;
        }

        return mp.size();
    }
};
