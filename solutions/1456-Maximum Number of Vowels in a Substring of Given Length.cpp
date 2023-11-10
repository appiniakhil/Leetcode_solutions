class Solution {
public:
    //Time Complexity :O(n) && Space Complexity :O(1)
    int noVowels(string s)
    {
        int n = s.size();
        int cnt = 0;
        for(int i=0;i<n;i++)
        {
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
            {
                cnt++;
            }
        }

        return cnt;
    }

    int maxVowels(string s, int k) {
        int n = s.size();
        int left = 0,maxi=0,curr=0;

        string sub = "";
        for(int right=0;right<n;right++)
        {
            curr += noVowels(s.substr(right, 1));
            if(right - left + 1 ==  k)
            {
                maxi = max(maxi, curr);
                curr -= noVowels(s.substr(left, 1));
                left++;

            }
        }

        return maxi;
    }
};
