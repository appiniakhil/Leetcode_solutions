class Solution {
public:
    //Time Complexity :O(logn) && Space Complexity :O(1)
    int reverse(int x)
    {
        long rev = 0;
        while(x > 0)
        {
            int dig = x%10;
            rev = rev*10 + dig;
            x = x/10;
        }

        return (int)rev;
    }

    bool isPalindrome(int x) {
        if(x<0)
        {
            return false;
        }
        
        return (reverse(x) == x);
    }
};
