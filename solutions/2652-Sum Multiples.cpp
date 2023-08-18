class Solution {
public:
    //Time Complexity :O(n) && Space Complexity :O(1)
    int sumOfMultiples(int n) {

        int sum = 0;
        for(int i=1;i<n+1;i++)
        {
            if(i%3 == 0 || i%5 ==0 || i%7 == 0)
            {
                sum += i;
            }
        }
        
        return sum;
    }
};
