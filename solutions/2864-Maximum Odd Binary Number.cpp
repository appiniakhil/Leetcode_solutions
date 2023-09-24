class Solution {
public:
    //Time Complexity :O(n) && Space Complexity :O(1)
    string maximumOddBinaryNumber(string s) {
        string ans ="";
        
        int n = s.size();
        
        int cntfor1 = 0;
        int cntfor0 = 0;
        
        for(int i=0;i<n;i++)
        {
            if(s[i] == '1')
            {
                cntfor1++;
            }
        }
        
        cntfor0 = n - cntfor1;
        
        if(cntfor1 == 1)
        {
            while(cntfor0 > 0)
            {
                ans += '0';
                cntfor0--;
            }
            
            ans += '1';
            
            return ans;
        }
        
        while(cntfor1>1)
        {
            ans += '1';
            cntfor1--;
        }
        
        while(cntfor0 > 0)
        {
            ans += '0';
            cntfor0--;
        }
        
        ans += '1';
        
        return ans;
    }
};
