class Solution {
public:
    //Brute Force Approach
    //Time Complexity :O(n * m) && Space Complexity :O(1)
    // int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
    //     int n = arr1.size();
    //     int m = arr2.size();

    //     int cnt = 0;
    //     for(int i=0;i<n;i++)
    //     {
    //         bool valid = true;
    //         for(int j=0;j<m;j++)
    //         {
    //             if(abs(arr1[i] - arr2[j]) <= d)
    //             {
    //                 valid = false;
    //                 break;
    //             }
    //         }

    //         if(valid)
    //         {
    //             cnt++;
    //         }
    //     }

    //     return cnt;
    // }

    //Time Complexity :O(nlogm) && Space Complexity :O(1)
    bool helper(vector<int>& arr, int target, int d)
    {
        int l = 0, h = arr.size() - 1;

        while(l <= h)
        {
            int mid = l + (h - l)/2;
            int diff = abs(arr[mid] - target);

            if(diff <= d)
            {
                return true;
            }
            
            if(arr[mid] < target)
            {
                l = mid+1;
            }
            else
            {
                h = mid-1;
            }
        }

        return false;
    }

    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {

        sort(arr2.begin(), arr2.end());
        int cnt = 0;

        for(int i : arr1)
        {
            if(!helper(arr2, i, d))
            {
                cnt++;
            }
        }

        return cnt;
    }
};
