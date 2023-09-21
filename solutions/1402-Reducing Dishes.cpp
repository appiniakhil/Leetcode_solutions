class Solution {
public:
    //Time Complexity :O(nlogn) && Space Complexity :O(1)
    int maxSatisfaction(vector<int>& satisfaction) {
        int n = satisfaction.size();

        sort(satisfaction.begin(),satisfaction.end());

        int maxiTime = 0, currTime= 0 , totSat = 0;

        for(int i=n-1;i>=0;i--)
        {
            totSat += satisfaction[i];
            currTime += totSat;

            if(currTime > maxiTime)
            {
                maxiTime = currTime;
            }
        }

        return maxiTime;
    }
};
