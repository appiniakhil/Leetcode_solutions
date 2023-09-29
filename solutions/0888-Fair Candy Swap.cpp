class Solution {
public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
        int sumA = 0;
        int sumB = 0;

        unordered_set<int> s;

        for(int i: aliceSizes)
        {
            sumA += i;
        }

        for(int j: bobSizes)
        {
            sumB += j;
            s.insert(j);
        }

        int target = (sumA + sumB) / 2;

        for(int i : aliceSizes) 
        {
            int candyGive = i;
            int candyRecieve = target - (sumA - candyGive);

            if(s.count(candyRecieve) > 0)
            {
                return {candyGive, candyRecieve};
            }
        }

        return {};
    }
};


