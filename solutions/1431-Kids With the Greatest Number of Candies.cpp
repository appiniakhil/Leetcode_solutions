class Solution {
public:
    //Bit Lengthy
    //Time Complexity :O(n) && Space Complexity :O(n)
    // vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
    //     int n = candies.size();
    //     vector<bool> res;
    //     int maxi = INT_MIN;
    //     for(int i=0;i<n;i++)
    //     {
    //         maxi = max(maxi, candies[i]);
    //     }

    //     for(int i=0;i<n;i++)
    //     {
    //         candies[i] += extraCandies;
    //     }

    //     for(int i=0;i<n;i++)
    //     {
    //         if(maxi > candies[i])
    //         {
    //             res.push_back(false);
    //         }
    //         else
    //         {
    //             res.push_back(true);
    //         }
    //     }

    //     return res;
    // }

    //Time Complexity :O(n) && Space Complexity :O(n)
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int n = candies.size();
        vector<bool> res;
        int maxi = *max_element(candies.begin(),candies.end());

        for(int i=0;i<n;i++)
        {
            if(maxi > candies[i] + extraCandies)
            {
                res.push_back(false);
            }
            else
            {
                res.push_back(true);
            }
        }

        return res;
    }
};
