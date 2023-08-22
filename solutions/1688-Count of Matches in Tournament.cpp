class Solution {
public:
    //Time Complexity :O(n) && Space Complexity :O(1)
    int numberOfMatches(int n) {
        int cnt = 0;

        while(n > 0)
        {
            if(n == 1)
            {
                break;
            }

            if(n %2 == 0)
            {
                cnt += n/2;
                n = n/2;
            }
            else
            {
                cnt += (n-1)/2;
                n = (n-1)/2 + 1;
            }
        }

        return cnt;
    }
};
