class Solution {
public:
    //Time Complexity :O(nlogn) && Space Complexity :O(1)
    // int maxOperations(vector<int>& nums, int k) {
    //     int n = nums.size();
    //     int i=0,j=n-1;

    //     sort(nums.begin(), nums.end());

    //     int cnt = 0;
    //     while(i < j)
    //     {
    //         if(nums[i] + nums[j] == k)
    //         {
    //             cnt++;
    //             i++;
    //             j--;
    //         }
    //         else if(nums[i] + nums[j] < k)
    //         {
    //             i++;
    //         }
    //         else
    //         {
    //             j--;
    //         }
    //     }

    //     return cnt;
    // }

    //Time Complexity :O(n) && Space Complexity :O(n)
    int maxOperations(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_map<int,int> freq;

        int cnt = 0;
        for(int i : nums)
        {
            int rem = k - i;
            if(freq.find(rem) != freq.end() && freq[rem] > 0)
            {
                cnt++;
                freq[rem]--;
            }
            else
            {
                freq[i]++;
            }
        }

        return cnt;
    }
};
