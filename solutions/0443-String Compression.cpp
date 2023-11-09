class Solution {
public:
    //Time Complexity :O(n) && Space Complexity :O(1)
    int compress(vector<char>& chars) {
        int i=0;
        int j=0;

        while(i < chars.size())
        {
            chars[j] = chars[i];
            int cnt = 0;
            while(i < chars.size() && chars[i] == chars[j])
            {
                i++;
                cnt++;
            }

            if(cnt > 1)
            {
                string strcnt = to_string(cnt);
                for(char c : strcnt)
                {
                    chars[++j] = c;
                }
            }

            j++;
        }
    
        return j;
    }
};
