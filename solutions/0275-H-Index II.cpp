class Solution {
public:
    //Time Complexity :O(n) && Space Complexity :O(1)
    // int hIndex(vector<int>& citations) {
    //     int n = citations.size();

    //     reverse(citations.begin(), citations.end());

    //     int ans = 0;
    //     for(int i=0;i<n;i++)
    //     {
    //         if(citations[i] >= i+1)
    //         {
    //             ans = i+1;
    //         }
    //         else
    //         {
    //             break;
    //         }
    //     }

    //     return ans;
    // }

    //Time Complexity :O(logn) && Space Complexity :O(1)
    int hIndex(vector<int>& citations) {
        int n = citations.size();

        int low = 0, high = n-1;

        while(low <= high)
        {
            int mid = low + (high - low)/2;
            if(citations[mid] >= n - mid)
            {
                high = mid-1;
            }
            else
            {
                low = mid+1;
            }
        }

        return n - low;
    }
};
