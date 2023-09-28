class Solution {
public:
    //Time Complexity :O(logn) && Space Complexity :O(1)
    char nextGreatestLetter(vector<char>& letters, char target) {
        int n = letters.size();

        int l = 0, h = n-1;

        while(l <= h)
        {
            int mid = l + (h-l)/2;

            if(letters[mid]  > target)
            {
                h = mid-1;
            }
            else
            {
                l = mid+1;
            }
        }

        if(l < n)
        {
            return letters[l];
        }
        
        return letters[0];
    }
};
