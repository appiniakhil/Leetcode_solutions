class Solution {
public:

    //Using Heap
    //Time Complexity: O(nlogk) && Space Complexity :O(k)
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<int, vector<int>, greater<int>> minH;

        for(int i=0;i<n;i++)
        {
            minH.push(nums[i]);

            if(minH.size() > k)
            {
                minH.pop();
            }
        }

        return minH.top();        
    }
};
