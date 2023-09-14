class Solution {
public:
    //Time Complexity :O(nlogn) && Space Complexity :O(1)
    // int longestConsecutive(vector<int>& nums) {
    //     int n = nums.size();

    //     if(n <= 1)
    //     {
    //         return n;
    //     }

    //     sort(nums.begin(), nums.end());

    //     int cnt = 1;
    //     int ans = 1;
    //     for(int i=1;i<n;i++)
    //     {
    //         if(nums[i] == nums[i-1])
    //         {
    //             continue;
    //         }
    //         else if(nums[i] == nums[i-1] + 1)
    //         {
    //             cnt++;
    //         }
    //         else
    //         {
    //             cnt = 1;
    //         }

    //         ans = max(ans, cnt);
    //     }

    //     return ans;
    // }

    //Time Complexity :O(n) && Space Complexity :O(1)
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();

        if(n <= 1)
        {
            return n;
        }

        set<int> s;

        for(int i : nums)
        {
            s.insert(i);
        }

        int cnt = 1;
        for(int i : nums)
        {
            if(!s.count(i-1))
            {
                int currnum = i;
                int currcnt = 1;

                while(s.count(currnum+1))
                {
                    currnum += 1;
                    currcnt += 1;
                }

                cnt = max(cnt, currcnt);
            }
        }

        return cnt;
    }
};
