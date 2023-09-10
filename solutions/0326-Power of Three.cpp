class Solution {
public:
    //Time Complexity :O(logn to the base 3) && Space Complexity :O(1)
    bool isPowerOfThree(int n) {
        if(n <= 0) 
        {
            return false; 
        }

        while (n % 3 == 0) 
        {
            n /= 3;
        }
        
        return n == 1;
    }
};
