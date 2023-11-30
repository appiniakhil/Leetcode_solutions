class Solution {
public:
    //Time Complexity :O(n) && Space3 Complexity :O(1)
    int minimumOneBitOperations(int n) {
        int res = 0;
        while(n)
        {
            res ^= n;
            n >>= 1;
        }

        return res;
    }
};
