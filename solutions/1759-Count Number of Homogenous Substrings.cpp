class Solution {
    //Time Complexity :O(n) && Space Complexity :O(1)
private:
    const int MOD = 1e9+7;
public:
    int countHomogenous(string s) {
        long long res = 0, cnt = 0;

        char prev = ' ';
        for(char c : s)
        {
            if(c == prev)
            {
                cnt += 1;
            }
            else
            {
                cnt = 1;
            }

            res = (res + cnt) % MOD;

            prev = c;
        }

        return res;
    }
};
