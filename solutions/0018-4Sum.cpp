class Solution {
public:
    //Time Complexity :O(n * n * n) && Space Complexity :O(1)
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();

        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());

        for(int i=0;i<n;i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            } 

            for(int j=i+1;j<n;j++)
            {
                if (j > i + 1 && nums[j] == nums[j - 1])
                {
                    continue;
                }
                int low = j+1, high = n-1;

                while(low < high)
                {
                    long sum = nums[i];
                    sum += nums[j];
                    sum += nums[low];
                    sum += nums[high];

                    if(sum == target)
                    {
                        vector<int> subans = {nums[i], nums[j], nums[low], nums[high]};

                        ans.push_back(subans);
                        low++;
                        high--;

                        while(low < high && nums[low] == nums[low-1])
                        {
                            low++;
                        }

                        while(low < high && nums[high] == nums[high+1])
                        {
                            high--;
                        }
                    }
                    else if(sum < target)
                    {
                        low++;
                    }
                    else
                    {
                        high--;
                    }
                }

            }
        }

        return ans;
    }
};
