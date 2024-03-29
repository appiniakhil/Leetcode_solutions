class Solution {
public:
    //Time Complexity :O(nlogn) && Space Complexity :O(1)
    bool canMakeArithmeticProgression(vector<int>& arr) {
        int n = arr.size();

        if(n < 3)
        {
            return true;
        }

        sort(arr.begin(), arr.end());

        int diff = arr[1] - arr[0];
        for(int i=1;i<n-1;i++)
        {
            if(arr[i+1] - arr[i] != diff)
            {
                return false;
            }
        }

        return true;
    }
};
