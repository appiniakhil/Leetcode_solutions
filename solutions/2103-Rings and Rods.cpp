class Solution {
public:
    //Time Complexity :O(nlogn) && Space Complexity :O(n)
    int countPoints(string rings) {
        map<int, string> mp;
        int ans = 0;

        for(int i=0;i<rings.size();i++)
        {
            mp[rings[i+1] - '0'] += rings[i];
        }

        for(int i=0;i<10;i++)
        {
            int R=0,G=0,B=0;

            string ch = mp[i];

            for(int i=0;i<ch.size();i++)
            {
                if(ch[i] == 'R')
                {
                    R=1;
                }
                if(ch[i] == 'G')
                {
                    G=1;
                }
                if(ch[i] == 'B')
                {
                    B=1;
                }
            }

            if(R==1 && G==1 && B==1)
            {
                ans++;
            }
        }

        return ans;
    }
};
