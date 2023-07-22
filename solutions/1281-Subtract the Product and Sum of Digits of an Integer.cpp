class Solution {
public:

    //Time Complexity :O(log n) && Space Compleity :O(1)
    int subtractProductAndSum(int n) {
        
        int sum = 0;
        int prod = 1;

        while(n>0)
        {
            int x = n%10;
            prod *= x;
            sum += x;
            n = n/10;
        }

        return prod-sum;
    }
};
