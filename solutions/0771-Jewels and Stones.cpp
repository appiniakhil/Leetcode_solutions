class Solution {
public:
    //Time Complexity :O(n * m) && Space Complexity :O(1)
    int numJewelsInStones(string jewels, string stones) {
        int cnt = 0;
        int n = jewels.size();
        int m = stones.size();

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(jewels[i] == stones[j])
                {
                    cnt++;
                }
            }
        }

        return cnt;
    }
};
