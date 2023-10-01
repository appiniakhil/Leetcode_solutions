/*
 * // This is the custom function interface.
 * // You should not implement it, or speculate about its implementation
 * class CustomFunction {
 * public:
 *     // Returns f(x, y) for any given positive integers x and y.
 *     // Note that f(x, y) is increasing with respect to both x and y.
 *     // i.e. f(x, y) < f(x + 1, y), f(x, y) < f(x, y + 1)
 *     int f(int x, int y);
 * };
 */

class Solution {
public:
    //Time Complexity :O(n * n) && Space Complexity :O(n * n)
    // vector<vector<int>> findSolution(CustomFunction& customfunction, int z) {
    //     vector<vector<int>> ans;

    //     for(int x=1;x<=1000;x++)
    //     {
    //         for(int y=1;y<=1000;y++)
    //         {
    //             if(customfunction.f(x, y) == z)
    //             {
    //                 ans.push_back({x, y});
    //             }
    //             else if(customfunction.f(x, y) > z)
    //             {
    //                 break;
    //             }
    //         }
    //     }

    //     return ans;
    // }

    //Time Complexity :O(nlogn) && Space Complexity :O(n * n)
    vector<vector<int>> findSolution(CustomFunction& customfunction, int z) {
        vector<vector<int>> ans;

        for(int x=1;x<=1000;x++)
        {
            int l = 1, h = 1000;
            while(l <= h)
            {
                int mid = l + (h-l)/2;
                if(customfunction.f(x, mid) == z)
                {
                    ans.push_back({x, mid});
                    break;
                }
                else if(customfunction.f(x, mid) > z)
                {
                    h = mid-1;
                }
                else
                {
                    l = mid+1;
                }
            }

            if(customfunction.f(x,1)>z)
            {
                break;
            }
        }

        return ans;
    }
};
