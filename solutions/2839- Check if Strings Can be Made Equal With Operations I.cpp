class Solution {
public:
    //Brute force
    //Time Complexity :O(1) && Space Complexity :O(1)
    // bool canBeEqual(string s1, string s2) {
    //     string temp1 = s1, temp2 = s1, temp3 = s1;

    //     swap(temp1[0], temp1[2]);
    //     swap(temp2[1], temp2[3]);
    //     swap(temp3[0], temp3[2]);
    //     swap(temp3[1], temp3[3]);

    //     if(s1 == s2 || temp1 == s2 || temp2 == s2 || temp3 == s2) 
    //     {
    //         return true;
    //     }
        
    //     return false;
    // }

    //Time Complexity :O(1) && Space Complexity :O(1)
    bool canBeEqual(string s1, string s2) {

        int i=0;
        while(i < 4)
        {
            if(s1[i] != s2[i])
            {
                swap(s1[i],s1[i+2]);
            }
            i++;
        }

        return (s1 == s2);
    }
};
