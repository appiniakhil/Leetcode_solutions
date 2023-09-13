class Solution {
public:

    // Time Limit Exceeded
    //Time Complexity :O(n * (sum - max + 1)) && Space Complexity :O(1)
    // int helper(vector<int>& weights,int capacity)
    // {
    //     int d = 1,load = 0;

    //     for(int i=0;i<weights.size();i++)
    //     {
    //         if(load + weights[i] > capacity)
    //         {
    //             d++;
    //             load = weights[i];
    //         }
    //         else
    //         {
    //             load += weights[i];
    //         }
    //     }

    //     return d;
    // }

    // int shipWithinDays(vector<int>& weights, int days) {
    //     int maxi = INT_MIN;
    //     int sum = 0;

    //     for(int i=0;i<weights.size();i++)
    //     {
    //         maxi = max(maxi, weights[i]);
    //         sum += weights[i];
    //     }

    //     for(int i=maxi;i<=sum;i++)
    //     {
    //         int daysReq = helper(weights,i);
    //         if(daysReq <= days)
    //         {
    //             return i;
    //         }
    //     }

    //     return -1;
    // }

    //Time Complexity :O(log(n * (sum - max + 1))) && Space Complexity :O(1)
    int helper(vector<int>& weights,int capacity)
    {
        int d = 1,load = 0;

        for(int i=0;i<weights.size();i++)
        {
            if(load + weights[i] > capacity)
            {
                d++;
                load = weights[i];
            }
            else
            {
                load += weights[i];
            }
        }

        return d;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int maxi = INT_MIN;
        int sum = 0;

        for(int i=0;i<weights.size();i++)
        {
            maxi = max(maxi, weights[i]);
            sum += weights[i];
        }

        int low = maxi, high = sum;

        while(low <= high)
        {
            int mid = low + (high-low)/2;
            if(helper(weights, mid) <= days)
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
