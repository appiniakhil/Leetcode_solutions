class Solution {
public:

    //Time Complexity :O(n) && Space Complexity :O(n)
    int largestAltitude(vector<int>& gain) {
        int n = gain.size();
        vector<int> alt;
        alt.push_back(0);

        int sum = 0;
        int maxi = INT_MIN;
        for(int i=0;i<n;i++)
        {
            sum += gain[i];
            alt.push_back(sum);
        }

        for(int i=0;i<n+1;i++)
        {
            maxi = max(maxi,alt[i]);
        }

        return maxi;
    }
};
