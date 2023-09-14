class Solution {
public:
    //Time Complexity :O(n + m) && Space Complexity :O(1)
    int getXORSum(vector<int>& arr1, vector<int>& arr2) {
        int n = arr1.size(), m = arr2.size();
        
        int xorop1 = 0, xorop2= 0;

        for(auto i : arr1)
        {
            xorop1 ^= i;
        }

        for(auto i : arr2)
        {
            xorop2 ^= i;
        }

        return xorop1 & xorop2;
    }
};
