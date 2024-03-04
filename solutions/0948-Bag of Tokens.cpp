class Solution {
public:
    //Time Complexity :O(nlogn) && Space Complexity :O(1)
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int score = 0, maxscore = 0;
        int n = tokens.size();

        sort(tokens.begin(), tokens.end());

        int left = 0, right = n-1;

        while(left <= right)
        {
            if(power >= tokens[left])
            {
                power -= tokens[left];
                score++;
                left++;

                maxscore = max(maxscore, score);
            }
            else if(score > 0)
            {
                power += tokens[right];
                score--;
                right--;
            }
            else
            {
                break;
            }
        }

        return maxscore;
    }
};
