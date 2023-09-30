class Solution {
public:
    //Brute Force
    //Time Complexity :O(n * n) && Space Complexity :O(1)
    //Time Limit Exceeded
    // bool find132pattern(vector<int>& nums) {
    //     int n = nums.size();

    //     for(int i=0;i<n;i++)
    //     {
    //         for(int j=i+1;j<n;j++)
    //         {
    //             for(int k=j+1;k<n;k++)
    //             {
    //                 if(i < j && j < k && nums[i] < nums[k] && nums[k] < nums[j])
    //                 {
    //                     return true;
    //                 }
    //             }
    //         }
    //     }

    //     return false;
    // }

    //Time Complexity :O(n) && Space Complexity :O(n)
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        
        if(n < 3) 
        {
            return false;
        }
        
        vector<int> mini(n);
        mini[0] = nums[0];

        for(int i=1;i<n;i++) 
        {
            mini[i] = min(mini[i - 1], nums[i]);
        }

        stack<int> s;

        for(int j=n-1;j>=0;j--) 
        {
            while(!s.empty() && s.top() <= mini[j]) 
            {
                s.pop();
            }

            if(!s.empty() && s.top() < nums[j]) 
            {
                return true;
            }

            s.push(nums[j]);
        }

        return false;
    }
};

