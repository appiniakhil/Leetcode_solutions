class Solution {
public:

    //Time Complexity :O(n * n) && Space Complexity :O(n)
    int uniqueMorseRepresentations(vector<string>& words) {
      	vector<string> a = {".-","-...","-.-.","-..",".","..-.","--.","....",
                  "..",".---","-.-",".-..","--","-.","---",".--.",
                  "--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};

            unordered_map<string,int> mp;

            for (int i=0; i< words.size(); i++) 
            {
                string s;
                for (int j=0; j<words[i].size(); j++) 
                {
                    s += a[words[i][j] - 'a'];
                }

                mp[s]=1;
            }

        return mp.size (); 
    }
};
