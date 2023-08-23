class Solution {
public:
    //Time Complexity :O(n * n) && Space Complexity :O(1)
    int maximumNumberOfStringPairs(vector<string>& words) {
        int cnt = 0;
        for(int i=0;i<words.size();i++)
        {
            for(int j=i+1;j<words.size();j++)
            {
                if(words[i][0] == words[j][1] && words[i][1] == words[j][0])
                {
                    cnt++;
                }
            }
        }

        return cnt;
    }
};
