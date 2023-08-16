class Solution {
public:
    //Time Complexity :O(n * n) && Space Complexity :O(n)
    int mostWordsFound(vector<string>& sentences) {
        int n = sentences.size();
        int res = 0;

        for(int i=0;i<n;i++)
        {
            string str = "";
            str += sentences[i];

            int count = 1;
            for(auto& it: str)
            {
                if(it == ' ')
                {
                    count++;
                }
            }

            res = max(res, count);
        }

        return res;
    }
};
