class Solution {
public:
    //Time Complexity :O(nlogn) && Space Complexity :O(1)
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(), piles.end(), greater<int>());

        int ans = 0;
        int n = piles.size();

        for(int i=1;i<n*2/3;i+=2)
        {
            ans += piles[i];
        }

        return ans;
    }
};
