class Solution {
public:
    //Time Complexity :O(1) && Space Complexity :O(1)
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int rounds = minutesToTest / minutesToDie;
        
        return ceil(log2(buckets) / log2(rounds + 1));
    }
};
