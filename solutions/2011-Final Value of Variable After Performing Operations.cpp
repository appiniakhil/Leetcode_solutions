class Solution {
public:
    //Time Complexity :O(n) && Space Complexity :O(1)
    int finalValueAfterOperations(vector<string>& operations) {
        int x = 0;

        for(auto& it : operations)
        {
            if(it[1] == '-')
            {
                x -= 1;
            }
            else
            {
                x += 1;
            }
        }

        return x;
    }
};
