class Solution {
public:
    //Time Complexity :O(nlogn) && Space Complexity :O(1)
    int buyChoco(vector<int>& prices, int money) {
        sort(prices.begin(), prices.end());
        
        int diff = money - prices[0] - prices[1];

        if(diff >= 0)
        {
            return diff;
        }

        return money;
    }
};
