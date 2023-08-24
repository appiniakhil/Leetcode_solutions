class Solution {
public:
    //Time Complexity :O(n) && Space Complexity :O(n)
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        vector<int> ans;

        unordered_map<int, int> freq;
        int n = A.size();
        int cnt = 0;

        for(int i=0;i<n;i++) 
        {
            freq[A[i]]++;
            freq[B[i]]++;
            if(A[i] == B[i] && freq[A[i]] == 2)
            {
                cnt++;
            }
            else 
            {
                if(freq[A[i]] == 2)
                {
                    cnt++;
                }
                if(freq[B[i]] == 2)
                {
                    cnt++;
                }
            }

            ans.push_back(cnt);
        }

        return ans;
    }
};
