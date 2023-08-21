class Solution {
public:

    //Time Complexity :O(n * m) && Space Complexity :O(n + m)
    vector<int> processQueries(vector<int>& queries, int m) {
        vector<int> P(m,0);
        vector<int> res;

        for(int i=0;i<m;i++)
        {
            P[i] = i+1;
        }
        
        int pos = 0, val;
        for(int i=0;i<queries.size();i++)
        {
            auto it = find(P.begin(), P.end(), queries[i]);
            pos = it - P.begin();
            val = P[pos];
            P.erase(it);
            P.insert(P.begin(), val);
            res.push_back(pos);
        }

        return res;
    }
};
