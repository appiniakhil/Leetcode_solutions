class Solution {
public:
    //Merge Sort
    //Time Complexity :O(nlogn) && Space Complexity :O(1)
    // Merge two subarrays L and M into arr
    void merge(vector<int>& nums, int p, int q, int r) 
    {
        int n1 = q - p + 1;
        int n2 = r - q;

        int L[n1], M[n2];

        for (int i = 0; i < n1; i++)
        {
            L[i] = nums[p + i];
        }
        for (int j = 0; j < n2; j++)
        {
            M[j] = nums[q + 1 + j];
        }

        // Maintain current index of sub-arrays and main array
        int i, j, k;
        i = 0;
        j = 0;
        k = p;

        // Until we reach either end of either L or M, pick larger among
        // elements L and M and place them in the correct position at A[p..r]
        while (i < n1 && j < n2) 
        {
            if (L[i] <= M[j]) 
            {
                nums[k] = L[i];
                i++;
            } 
            else 
            {
                nums[k] = M[j];
                j++;
            }
            k++;
        }

        // When we run out of elements in either L or M,
        // pick up the remaining elements and put in A[p..r]
        while (i < n1) 
        {
            nums[k] = L[i];
            i++;
            k++;
        }

        while (j < n2) 
        {
            nums[k] = M[j];
            j++;
            k++;
        }
    }

    // Divide the array into two subarrays, sort them and merge them
    void mergeSort(vector<int>& nums, int l, int r) 
    {
        if (l < r) {
            // m is the point where the array is divided into two subarrays
            int m = l + (r - l) / 2;

            mergeSort(nums, l, m);
            mergeSort(nums, m + 1, r);

            // Merge the sorted subarrays
            merge(nums, l, m, r);
        }
    }

    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        mergeSort(nums,0,n-1);

        return nums;
    }
};
