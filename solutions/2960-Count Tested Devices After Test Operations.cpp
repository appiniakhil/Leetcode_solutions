class Solution {
public:
    //Time Complexity :O(n * n) && Space Complexity :O(1)
    int countTestedDevices(vector<int>& batteryPercentages) {
        int n = batteryPercentages.size();
        
        int cnt = 0;
        for(int i=0;i<n;i++)
        {
            if(batteryPercentages[i] > 0)
            {
                cnt++;
                for(int j=i+1;j<n;j++)
                {
                    if(batteryPercentages[j] >= 0)
                    {
                        batteryPercentages[j] = max(0, batteryPercentages[j] - 1);
                    }
                }
            }
        }
        
        return cnt;
    }
};
