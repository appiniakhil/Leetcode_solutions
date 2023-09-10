class Solution {
public:
    //Time Complexity :O(logn base to 4) && Space Complexity :O(1)
    bool isPowerOfFour(int n) {
        if(n <= 0) 
        {
            return false; 
        }

        while (n % 4 == 0) 
        {
            n /= 4;
        }
        
        return n == 1;
    }
};
