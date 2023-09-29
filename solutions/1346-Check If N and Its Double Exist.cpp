class Solution {
public:
    //Brute Force Approach
    //Time Complexity :O(n * n) && Space Complexity :O(1)
    // bool checkIfExist(vector<int>& arr) {
    //     int n = arr.size();

    //     for(int i = 0;i<n;i++)
    //     {
    //         for(int j = i+1;j<n;j++)
    //         {
    //             if(arr[i] == 2 * arr[j] || arr[j] == 2 * arr[i])
    //             {
    //                 return true;
    //             }
    //         }
    //     }

    //     return false;
    // }

    //Time Complexity :O(nlogn) && Space Complexity :O(1)
    bool helper(vector<int>& arr, int target)
    {
        int n = arr.size();
        int l = 0, h = n-1;

        while(l <= h)
        {
            int mid = l + (h - l)/2;
            if(arr[mid] == target)
            {
                return true;
            }
            else if(arr[mid] < target)
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

    bool checkIfExist(vector<int>& arr) {
        int n = arr.size();
        
        sort(arr.begin(), arr.end());
        int cnt0 = 0;

        for(int i = 0;i<n;++i)
        {
            if(arr[i] == 0)
            {
                cnt0++;
                {
                    if(cnt0 > 1)
                    {
                        return true;
                    }
                }
            }
            else
            {
                int val = 2 * arr[i];
                if(helper(arr, val))
                {
                    return true;
                }
            }
        }

        return false;
    }
};
