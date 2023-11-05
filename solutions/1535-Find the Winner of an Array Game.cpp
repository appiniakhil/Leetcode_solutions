class Solution {
public:
    //Time Complexity :O(n) && Space Complexity :O(1)
    int getWinner(vector<int>& arr, int k) {
        int n = arr.size();

        if(k == 1)
        {
            return max(arr[0],arr[1]);
        }

        if(k >= n)
        {
            int maxi = 0;
            for(int i=0;i<n;i++)
            {
                maxi = max(maxi, arr[i]);
            }

            return maxi;
        }

        int currW = arr[0];
        int cons = 0;

        for(int i=1;i<n;i++)
        {
            if(currW > arr[i])
            {
                cons++;
            }
            else
            {
                currW = arr[i];
                cons = 1;
            }

            if(cons == k)
            {
                return currW;
            }
        }

        return currW;
    }
};
