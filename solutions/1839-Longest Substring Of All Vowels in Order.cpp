class Solution {
public:
    //Time Complexity :O(n) && Space Complexity :O(1)
    int longestBeautifulSubstring(string word) {
        int n = word.size();

        int res=0, cnt=1, vow=1;

        for(int i=1;i<n;i++)
        {
            if(word[i] >= word[i-1])
            {
                if(word[i] > word[i-1])
                {
                    vow++;
                }
                cnt++;

                if(vow == 5)
                {
                    res = max(res, cnt);
                }
            }
            else
            {
                cnt = 1;
                vow = 1;
            }
        }

        return res;
    }
};
