class Solution {
public:
    //Time Complexity: O(1) && Space Complexity :O(1)
    int getSum(int a, int b) {
        while (b != 0) {
            // Calculate the carry
            int carry = a & b;
            
            // Sum of bits without considering carry
            a = a ^ b;
            
            // Carry is shifted by one so that adding it to a gives the correct sum
            b = (unsigned int)(carry) << 1;
        }
        
        return a;  
    }
};
