class Solution {
public:
    //Time Complexity :O(logn) && Space Complexity :O(1)
    bool isPerfectSquare(int num) {
        if(num < 2)
        {
            return true;
        }

        long low = 2,high = num/2;
        while(low <= high)
        {
            long mid = low + (high - low)/2;
            long square = mid * mid;

            if(num == square)
            {
                return true;
            }
            else if(square < num)
            {
                low = mid+1;
            }
            else
            {
                high = mid-1;
            }
        }

        return false;
    }
};
