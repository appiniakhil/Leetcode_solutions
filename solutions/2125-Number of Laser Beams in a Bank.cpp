class Solution {
public:
    //Time complexity: O(m * n) && Space complexity: O(1) where m is the number of rows and n is the number of columns in the bank
    int numberOfBeams(vector<string>& bank) {
        int prevRowCount = 0;
        int tot = 0;

        for(string& row : bank) 
        {
            int curRowCount = calc(row);
            if(curRowCount == 0)
            {
                continue;                
            }

            tot += curRowCount * prevRowCount;
            prevRowCount = curRowCount;
        }

        return tot;
    }

private:
    int calc(string& s) 
    {
        int cnt = 0;

        for(char c : s)
        {
            cnt += c - '0';            
        }

        return cnt;
    }
};
