class Solution {
public:
    //Time Complexity :O(n) && Space Complexity :O(n)
    string destCity(vector<vector<string>>& paths) {
        unordered_set<string> cities;

        for(auto& path : paths)
        {
            cities.insert(path[0]);
        }

        for(auto& path : paths)
        {
            if(!cities.count(path[1]))
            {
                return path[1];
            }
        }

        return "";
    }
};
