class Solution {
public:
    //Time Complexity :O(n * n) && Space Complexity :O(n)
    // int maxScore(string s) {
    //     int n = s.size();
    //     int maxi = INT_MIN;

    //     for(int i=0;i<n-1;i++)
    //     {
    //         string s1 = s.substr(0, i+1);
    //         string s2 = s.substr(i+1, n-i-1);

    //         int score = count(s1.begin(), s1.end(),'0') + count(s2.begin(), s2.end(),'1');
    //         maxi = max(maxi, score);
    //     }

    //     return maxi;
    // }

    //Time Complexity :O(n) && Space Complexity :O(1)
    int maxScore(string s) {
        int n = s.size();
        int onescnt = count(s.begin(), s.end(), '1');
        int zeroescnt = 0;
        int maxi = INT_MIN;

        for(int i=0;i<n-1;i++)
        {
            if(s[i] == '0')
            {
                zeroescnt++;
            }
            else
            {
                onescnt--;
            }

            maxi = max(maxi, zeroescnt + onescnt);
        }

        return maxi;
    }
};
