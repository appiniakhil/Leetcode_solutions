class Solution {
public:
    //Time Complexity :O(logn) && Space Complexity :O(1)
    int divide(int dividend, int divisor) {
        if(dividend == 1<<31 && divisor == -1)
        {
            return INT_MAX;
        }
        

        bool sign = (dividend >= 0) == (divisor >= 0) ? true : false;

        long long divid = llabs((long long)dividend);
        long long divis = llabs((long long)divisor);

        long long res = 0;
        while(divid- divis >= 0)
        {
            int cnt = 0;

            while(divid - (divis << 1 << cnt) >= 0)
            {
                cnt++;
            }

            res += 1LL << cnt;
            divid -= divis << cnt;
        }

        return sign?(int)res : (int)-res;
    }
};
