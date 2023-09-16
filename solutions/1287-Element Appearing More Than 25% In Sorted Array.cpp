class Solution {
public:

    //Time Complexity :O(n) && Space Complexity :O(1)
    int findSpecialInteger(vector<int>& arr) {
        int n = arr.size();
        int ans = n/4;
        int cnt = 1;

        for(int i = 1;i<arr.size();i++)
        {
            if(arr[i] == arr[i-1])
            {
                cnt++;
                if(cnt > ans)
                {
                    return arr[i];
                }
            }
            else
            {
                cnt = 1;
            }
        }

        return 1;
    }
};
