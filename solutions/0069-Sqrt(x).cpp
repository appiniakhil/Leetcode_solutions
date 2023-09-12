class Solution {
public:
    //Time Complexity : O(n) && Space Complexity :O(1)
    // int mySqrt(int x) {
    //     if(x == 1)
    //     {
    //         return 1;
    //     }

    //     int ans = 0;

    //     for(long i=0;i<x;i++)
    //     {
    //         if(i * i <= x)
    //         {
    //             ans = i;
    //         }
    //         else
    //         {
    //             break;
    //         }
    //     }

    //     return ans;
    // }

    //Time Complexity : O(logn) && Space Complexity :O(1)
    int mySqrt(int x) {
        int low = 0,high=x;
        
        while(low <= high)
        {
            long mid = low + (high-low)/2;
            if(mid * mid == x)
            {
                return mid;
            }
            else if(mid * mid > x)
            {
                high = mid-1;
            }
            else
            {
                low = mid+1;
            }
        }
        
        return high;
    }
};
