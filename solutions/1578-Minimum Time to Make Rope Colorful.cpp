class Solution {
public:
    //Time Complexity :O(n) && Space Complexity :O(n)
    int helper(int i, string& colorSeq, vector<int>& time, vector<int>& v, char prevColor, int prevTime)
    {
        if(i<0)
        {
            return 0;
        }

        if(v[i] != -1)
        {
            return v[i];
        }

        if(colorSeq[i] == prevColor)
        {
            return v[i] = helper(i-1,colorSeq,time,v,colorSeq[i],max(time[i], prevTime)) + min(time[i], prevTime);
        }
        else
        {
            return v[i] = helper(i-1,colorSeq,time,v,colorSeq[i],time[i]);
        }
    }

    int minCost(string colors, vector<int>& neededTime) {
        int n = colors.size();

        vector<int> dp(n, -1);

        return helper(n-1, colors, neededTime,dp,'A',neededTime[n-1]);
    }
};
