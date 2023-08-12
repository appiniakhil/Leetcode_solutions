class Solution {
public:

    //Time Complexity :O(1) && Space Complexity :O(1)
    bool isSameAfterReversals(int num) {
        if(num == 0)
        {
            return true;
        }

        if(num%10 == 0)
        {
            return false;;
        }

        return true;
    }
};
