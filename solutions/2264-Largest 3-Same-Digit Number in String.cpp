class Solution {
public:
    //Time Complexity :O(n) && Space Complexity :O(1)
    string largestGoodInteger(string num) {
        int n = num.length();

        string maxi = "";

        for(int i=0;i<=n - 3;i++) 
        {
            if(num[i] == num[i + 1] && num[i + 1] == num[i + 2]) 
            {
                if(maxi.empty() || num.substr(i, 3) > maxi) 
                {
                    maxi = num.substr(i, 3);
                }
            }
        }

        return maxi;
    }
};
