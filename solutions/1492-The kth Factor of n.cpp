class Solution {
public:

    //Time and Complexity :O(n) and Space Complexity :O(n)
    // int kthFactor(int n, int k) {
    //     vector<int> temp;

    //     for(int i=1;i<=n;i++)
    //     {
    //         if(n%i == 0)
    //         {
    //             temp.push_back(i);
    //         }
    //     }

    //     int tempSize = temp.size();
    //     if(tempSize >= k)
    //     {
    //         return temp[k-1];
    //     }

    //     return -1;
    // }

    //Time Complexity :O(n) && Space Complexity :O(1)
    int kthFactor(int n, int k) {
        int fact=0;

        for(int i=1;i<=n;i++)
        {
            if(n%i == 0)
            {
                fact++;
            }

            if(fact == k)
            {
                return i;
            }
        }

        return -1;
    }
};
