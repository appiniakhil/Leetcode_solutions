class Solution {
public:

    //Time Complexity :O(log n) && Space Complexity :O(1)
    double myPow(double x, int n) {
        double ans = 1.0;
        long long a = n;

        if(a < 0)
        {
            a = -1 * a;
        }

        while(a)
        {
            if(a % 2)
            {
                ans *= x;
                a--;
            }
            else
            {
                x *= x;
                a /= 2;
            }
        }

        if(n < 0)
        {
            ans = (double)(1.0) / (double)(ans);
        }

        return ans;
    }
};
