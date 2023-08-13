class Solution {
public:

    //Time Complexity :O(n) && Space Complexity:O(1)
    int helper(int x)
    {
        long num = 0;
        while(x != 0)
        {
            num = num*10 + x%10;
            x /= 10;
        }

        if(num > INT_MAX || num < INT_MIN)
        {
            return 0;
        }

        return (int)num;
    }

    int reverse(int x) {
        return helper(x);
    }
};
