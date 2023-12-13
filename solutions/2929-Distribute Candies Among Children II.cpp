class Solution {
public:
    //Time Complexity :O(1) && Space Complexity :O(1)
    long long distributeCandies(int n, int limit) {
        long long cnt = 0;

        for(int i = max(0, n-2*limit);i<=min(limit, n);i++) 
        {
            int j = min(limit, n-i)-max(0,n-i-limit) + 1;
            cnt += max(0, j);
        }

        return cnt;
    }
};
