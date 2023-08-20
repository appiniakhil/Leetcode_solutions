class Solution {
public:
    //Time Complexity :O(n * n) && Space Complexity :O(1)
    // int countPairs(vector<int>& nums, int target) {
    //     int n = nums.size();
    //     int cnt = 0;

    //     for(int i=0;i<n;i++)
    //     {
    //         for(int j=i+1;j<n;j++)
    //         {
    //             if(nums[i] + nums[j] < target)
    //             {
    //                 cnt++;
    //             }
    //         }
    //     }

    //     return cnt;
    // }

    //Time Complexity :O(nlogn) && Space Complexity :O(1)
    int countPairs(vector<int>& nums, int target) {
        int n = nums.size();
        int i=0;
        int j=n-1;
        int cnt = 0;

        sort(nums.begin(),nums.end());
        while(i<j)
        {
            if(nums[i] + nums[j] < target)
            {
                cnt += (j-i);
                i++;
            }
            else
            {
                j--;
            }
        }

        return cnt;
    }
};
