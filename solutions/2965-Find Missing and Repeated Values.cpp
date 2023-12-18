class Solution {
public:
       //Time Complexity :O((n*m)log(n*m)) && Space Complexity :O(n*m)
//     vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
//         int n = grid.size();
//         int m = grid[0].size();
        
//         vector<int> arr;
        
//         for(int i=0;i<n;i++)
//         {
//             for(int j=0;j<n;j++)
//             {
//                 arr.push_back(grid[i][j]);
//             }
//         }
        
//         sort(arr.begin(), arr.end());
        
//         vector<int> ans;
        
//         for(int i=0;i<arr.size()-1;i++)
//         {
//             if(arr[i] == arr[i+1])
//             {
//                 ans.push_back(arr[i]);
//             }
//         }
        
//         for(int i=0;i<arr.size()-1;i++)
//         {
//             if(arr[i+1] - arr[i] > 1)
//             {
//                 ans.push_back(arr[i] + 1);
//             }
//         }
        
//         if(ans.size() == 2)
//         {
//             return ans;
//         }
        
//         if(arr[0] != 1)
//         {
//             ans.push_back(1);
//         }
        
//         if(ans.size() == 2)
//         {
//             return ans;
//         }
        
//         if(arr[n-1] != n * n)
//         {
//             ans.push_back(n*n);
//         }
        
//         return ans;
//     }
    
    //Time Complexity :O(n*n) && Space Complexity :O(n*n)
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        
        unordered_set<int> arr;
        int repeated, missing;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(arr.count(grid[i][j]))
                {
                    repeated = grid[i][j];
                }
                else
                {
                    arr.insert(grid[i][j]);
                }
            }
        }
        
        for(int i=1;i<=n*n;i++)
        {
            if(!arr.count(i))
            {
                missing = i;
                break;
            }
        }

        return {repeated, missing};
    }
};
