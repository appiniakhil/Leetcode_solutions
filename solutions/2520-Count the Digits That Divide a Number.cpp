class Solution {
public:

    //Time Complexity :O(log n) && Space Complexity : O(1)
    int countDigits(int num) {
        int count = 0;
        int  y = num;
        while(num > 0)
        {
            int x = num%10;
            if(y%x == 0)
            {
                count++;
            }
            num = num/10;
        }

        return count;
    }
};
