class Solution {
public:
    //Time Complexity :O(logn) && Space Complexity :O(logn)
    int helper(int n)
    {
        int sum = 0;

        while(n > 0)
        {
            int dig = n % 10;
            sum += dig * dig;
            n = n/10;
        }

        return sum;
    }

    bool isHappy(int n) {
        set<int> seen;

        while(n != 1 && seen.find(n) == seen.end())
        {
            seen.insert(n);
            n = helper(n);
        }

        return n == 1;
    }
};
