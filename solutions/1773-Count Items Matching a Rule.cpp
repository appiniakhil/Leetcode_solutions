class Solution {
public:

    //Time Complexity :O(n) && Space Complexity :O(1)
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        int n = items.size();

        int cnt = 0;
        for(int i=0;i<n;i++)
        {
            if(ruleKey == "color")
            {
                if(items[i][1] == ruleValue)
                {
                    cnt++;
                }
            }
            else if(ruleKey == "type")
            {
                if(items[i][0] == ruleValue)
                {
                    cnt++;
                }
            }
            else
            {
                if(items[i][2] == ruleValue)
                {
                    cnt++;
                }
            }
        }

        return cnt;
    }
};
