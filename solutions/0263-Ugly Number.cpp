class Solution {
public:

    //Time Complexity :O(logn) && Space Complexity :O(1)
    bool isUgly(int n) {
        if (n <= 0) 
        {
            return false;
        }
        
        while (n % 2 == 0) 
        {
            n /= 2;
        }

        while (n % 3 == 0) 
        {
            n /= 3;
        }

        while (n % 5 == 0) 
        {
            n /= 5;
        }
        
        if(n == 1)
        {
            return true;
        }

        return false;
    }
};
