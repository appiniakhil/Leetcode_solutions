class Solution {
public:
    //Time Complexity :O(n) && Space Complexity :O(n)
    bool validateBinaryTreeNodes(int n, std::vector<int>& leftChild, std::vector<int>& rightChild) {
        vector<int> inDeg(n, 0);

        for(int i=0;i<n;i++) 
        {
            if(leftChild[i] != -1) 
            {
                inDeg[leftChild[i]]++;
            }

            if(rightChild[i] != -1) 
            {
                inDeg[rightChild[i]]++;
            }
        }

        int zeroInDegCnt = 0;
        int zeroInDegNode = -1;

        for(int i = 0;i<n;i++) 
        {
            if(inDeg[i] == 0) 
            {
                zeroInDegCnt++;
                zeroInDegNode = i;
            } 
            else if(inDeg[i] > 1) 
            {
                return false;
            }
        }

        if(zeroInDegCnt != 1) 
        {
            return false;
        }

        vector<bool> vis(n, false);

        dfs(zeroInDegNode, leftChild, rightChild, vis);
        for(int i = 0;i<n;i++) 
        {
            if(!vis[i]) 
            {
                return false;
            }
        }

        return true;
    }

    void dfs(int node, vector<int>& leftChild, vector<int>& rightChild, vector<bool>& vis) 
    {
        if(node == -1 || vis[node]) 
        {
            return;
        }

        vis[node] = true;

        dfs(leftChild[node], leftChild, rightChild, vis);
        dfs(rightChild[node], leftChild, rightChild, vis);
    }

};
