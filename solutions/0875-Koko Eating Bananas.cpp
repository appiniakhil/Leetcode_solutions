class Solution {
public:
    //Time Complexity :O(logn) && Space Complexity :O(1)
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxiEle = INT_MIN;
        int n = piles.size();

        for(int i=0;i<n;i++)
        {
            maxiEle = max(maxiEle, piles[i]);
        }

        int low = 1, high = maxiEle;
        while(low <= high)
        {
            int mid = low + (high-low)/2;
            long long total_hours = 0;

            for (int pile : piles) 
            {
                total_hours += (pile + mid - 1) / mid;  
            }

            if(total_hours <= h)
            {
                high = mid-1;
            }
            else
            {
                low = mid+1;
            }
        }

        return low;
    }
};
