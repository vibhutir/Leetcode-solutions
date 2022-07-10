class Solution {
public:
    
        void dfs(vector<vector<int>>& heights, int row, int col, int prev, vector<vector<int>>& ocean)
        {
            // out of of bound check
            if(row<0 || col<0 || row>=heights.size() || col >= heights[0].size())
                return;
            
            // water flow check
            if(heights[row][col]<prev)
                return;
            
            // visited check
            if(ocean[row][col] == -1)
                return;
            
            // visited node 
            ocean[row][col] = -1;
            
            //dfs in all four directions
            dfs(heights, row+1, col, heights[row][col], ocean);
            dfs(heights, row-1, col, heights[row][col], ocean);
            dfs(heights, row, col+1, heights[row][col], ocean);
            dfs(heights, row, col-1, heights[row][col], ocean);
            
        }
      
        vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
            
            vector<vector<int>> ans;
            
            if(heights.size() ==0)
                return ans;
            
            vector<vector<int>> pacific (heights.size(), vector<int>(heights[0].size(),0));
            vector<vector<int>> atlantic (heights.size(), vector<int>(heights[0].size(),0));
        
            for(int col =0; col<heights[0].size(); col++)
            {
                dfs(heights, 0, col, INT_MIN, pacific);
                dfs(heights, heights.size()-1, col, INT_MIN, atlantic);
                
            }
            
            for(int row =0; row<heights.size(); row++)
            {
                dfs(heights, row, 0, INT_MIN, pacific);
                dfs(heights, row, heights[0].size()-1, INT_MIN, atlantic);
                
            }
            
            vector<int> v;
            
            for (int i=0; i<heights.size(); i++)
            {
                for(int j=0; j<heights[0].size(); j++)
                {
                    if(pacific[i][j] == -1 && atlantic[i][j] == pacific[i][j])
                    {
                        v.clear();
                        v.push_back(i);
                        v.push_back(j);
                        ans.push_back(v);
                    }
                }
            }
            return ans;
        }
};
