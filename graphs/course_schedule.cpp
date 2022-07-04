class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
      
        unordered_map<int, vector<int>> um;
        vector<int> visited(numCourses,0);
        
        for (auto p: prerequisites)
        {
            um[p[0]].push_back(p[1]);
        }
        
        for (int i=0; i< numCourses; i++)
        {
            if(!traverse(visited, um, i))
                return false;
        }
        return true;
    }
    
    bool traverse(vector<int>& visited, unordered_map<int, vector<int>>& um, int i)
    {
        if (visited[i] == 10)
            return false;
        if (visited[i] == 1)
            return true;
        
        visited[i] = 10;
        
        for (auto c: um[i])
        {
            if(!traverse(visited, um, c))
                return false;
        }
        
        visited[i] = 1;
        return true;
    }
};
