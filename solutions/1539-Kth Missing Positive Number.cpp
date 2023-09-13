class Solution {
public:
    //Time Complexity :O(n) && Space Complexity :O(1)
    // int findKthPositive(vector<int>& arr, int k) {

    //     for(int i=0;i<arr.size();i++)
    //     {
    //         if(arr[i] <= k)
    //         {
    //             k++;
    //         }
    //         else
    //         {
    //             break;
    //         }
    //     }

    //     return k;
    // }

    //Time Complexity :O(logn) && Space Complexity :O(1)
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();

        int low = 0, high = n-1;

        while(low <= high)
        {
            int mid = low + (high-low)/2;
            int mis = arr[mid] - (mid+1);
            
            if(mis < k)
            {
                low = mid+1;
            }
            else
            {
                high =mid-1;
            }
        }

        return low + k;
    }
};
