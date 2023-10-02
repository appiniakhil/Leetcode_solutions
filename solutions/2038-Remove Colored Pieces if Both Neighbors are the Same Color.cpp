class Solution {
public:
    //Time Complexity :O(n) && Space Complexity :O(1)
    bool winnerOfGame(string colors) {
        int n = colors.size();
        int cntA = 0;
        int cntB = 0;

        for(int i=0;i<n-2;i++) 
        {
            if(colors[i] == 'A' && colors[i + 1] == 'A' && colors[i + 2] == 'A') 
            {
                cntA++;
            }
            else if(colors[i] == 'B' && colors[i + 1] == 'B' && colors[i + 2] == 'B') 
            {
                cntB++;
            }
        }

        return cntA > cntB;
    }
};
