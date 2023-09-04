class Solution {
public:
    //Time Complexity :O(d) && Space Complexity :O(d) where d is the no of digits in num
    int helper(int num)
    {
        int sum = 0;
        while(num > 0)
        {
            int dig = num%10;
            sum += dig;
            num /= 10;
        }

        return sum;
    }

    int addDigits(int num) {
        if(num <=9)
        {
            return num;
        }

        int sum = helper(num);
        while(sum>9)
        {
            int s = helper(sum);
            sum = s;
        }

        return sum;
    }
};
