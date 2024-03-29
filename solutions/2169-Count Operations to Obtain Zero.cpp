class Solution {
public:
    //Time Complexity :O(num1 + num2) && Space Complexity :O(1)
    int countOperations(int num1, int num2) {
        int count = 0;
        while(num1 > 0 && num2 > 0)
        {
            if(num1 < num2)
            {
                num2 -= num1;
                count++;
            }
            else if(num1 > num2)
            {
                num1 -= num2;
                count++;
            }
            else
            {
                count++;
                break;
            }
        }

        return count;
    }
};
