class Solution {
public:
    //Time Complexity :O(n) && Space Complexity :O(1)
    int trap(vector<int>& height) {
        int n = height.size();

        if(n == 0)
        {
            return 0;
        }

        int l = 0, r = n-1;
        int maxil = 0, maxir = 0;

        int ans = 0;

        while(l <= r)
        {
            if(height[l] <= height[r])
            {
                if(height[l] >= maxil)
                {
                    maxil = height[l];
                }
                else
                {
                    ans += maxil - height[l];
                }
                l++;
            }
            else
            {
                if(height[r] >= maxir)
                {
                    maxir = height[r];
                }
                else
                {
                    ans += maxir - height[r];
                }
                r--;
            }
        }

        return ans;
    }
};
