class Solution {
public:
    //Time Complexity :O(n + m) && Space Complexity :O(n) where n is the size of travel and m is the size of garbage;
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int res = 0;

        int lM = 0, lP = 0, lG = 0;
        int cntM = 0, cntP = 0, cntG = 0;

        vector<long long> prefix(travel.size() + 1);
        prefix.push_back(0);

        for(int i=1;i<=travel.size();i++)
        {
            prefix[i] = prefix[i-1] + travel[i-1];
        }

        for(int i=0;i<garbage.size();i++)
        {
            string s = garbage[i];

            for(auto c: s)
            {
                if(c == 'M')
                {
                    cntM++;
                    lM = i;
                }
                else if(c == 'P')
                {
                    cntP++;
                    lP = i;
                }
                else
                {
                    cntG++;
                    lG = i;
                }
            }
        }

        if(cntM)
        {
            res += (cntM + prefix[lM]);
        }

        if(cntP)
        {
            res += (cntP + prefix[lP]);
        }

        if(cntG)
        {
            res += (cntG + prefix[lG]);
        }

        return res;
    }
};
