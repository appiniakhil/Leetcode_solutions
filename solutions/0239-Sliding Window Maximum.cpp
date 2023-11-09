class Solution {
public:
    //Naive Approach
    //Time Limit Exceeded
    // vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    //     int n = nums.size();
    //     vector<int> ans;
    //     if (n == 0)
    //     {
    //         return ans;
    //     } 

    //     for(int i=0;i<=n-k;i++) 
    //     {
    //         int maxi = INT_MIN;
    //         for(int j=i;j<i+k;j++) 
    //         {
    //             maxi = max(maxi, nums[j]);
    //         }
    //         ans.push_back(maxi);
    //     }

    //     return ans;
    // }

    //Time Complexity :O(n) && Space Complexity :O(n)
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> ans;
        deque<int> dq;

        for(int i=0;i<n;i++)
        {
            while(!dq.empty() && dq.front() < i-k+1)
            {
                dq.pop_front();
            }

            while(!dq.empty() && nums[dq.back()] < nums[i])
            {
                dq.pop_back();
            }

            dq.push_back(i);

            if(i >= k-1)
            {
                ans.push_back(nums[dq.front()]);
            }
        }

        return ans;
    }
};
