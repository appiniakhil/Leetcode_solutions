class Solution {
public:
    //Brute Force Approach
    //Time Limit Exceeded
    // int arrangeCoins(int n) {
    //     long long cnt = 0;

    //     for(long long i=1;i<=n;i++)
    //     {
    //         long long sum = (i * (i+1))/2;
    //         if(sum <= n)
    //         {
    //             cnt++;
    //         }
    //     }

    //     return (int)cnt;
    // }

    //Time Complexity :O(logn) && Space Complexity :O(1)
    int arrangeCoins(int n) {
        long long l = 0;
        long long h = n;

        while(l <= h)
        {
            long long mid = l + (h-l)/2;
            long long sum = (mid * (mid+1))/2;
            if(sum == n)
            {
                return mid;
            }
            else if(sum < n)
            {
                l = mid+1;
            }
            else
            {
                h = mid-1;
            }
        }

        return (int)h;
    }
};
