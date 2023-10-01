class Solution {
public:
    //Time Complexity :O(n) && Space Complexity :O(1)
    // int peakIndexInMountainArray(vector<int>& arr) {
    //     int n = arr.size();
    //     for(int i=1;i<n-1;i++)
    //     {
    //         if(arr[i-1] < arr[i] && arr[i] > arr[i+1])
    //         {
    //             return i;
    //         }
    //     }

    //     return -1;
    // }

    //Time Complexity :O(logn) && Space Complexity :O(1)
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size();

        int l = 0, h = n-1;
        while(l < h)
        {
            int mid = l + (h-l)/2;
            if(arr[mid] > arr[mid+1])
            {
                h = mid;
            }
            else
            {
                l = mid+1;
            }
        }

        return l;
    }
};
