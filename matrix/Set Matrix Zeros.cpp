class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        
        // O(1) solution
        
        int m = matrix.size();
        int n = matrix[0].size();
        int x = 1; //make 0 if there is a 0 in the row
        int y = 1;
            
        for (int i=0; i<n ; i++)
            if(matrix[0][i] == 0) x=0;
        
        for (int i=0; i<m ; i++)
            if(matrix[i][0] == 0) y=0;
        
        for (int i=1; i<m ; i++)
        {
            for (int j=1; j<n ; j++)
            {
                if (matrix[i][j] == 0)
                {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        
        for (int j=1; j<n ; j++)    //1 cuz x will take care of 0th position
        {
            if (matrix[0][j] == 0)
            {
                for (int i=1; i<m ; i++)
                    matrix[i][j] = 0;
            }
        }
        
        for (int i=1; i<m ; i++)    //1 cuz y will take care of 0th position
        {
            if (matrix[i][0] == 0)
            {
                for (int j=1; j<n ; j++)
                    matrix[i][j] = 0;
            }
        }
        
        if(x==0)
        {
            for (int j=0; j<n ; j++)
                    matrix[0][j] = 0;
        }
        
        if(y==0)
        {
            for (int i=0; i<m ; i++)
                    matrix[i][0] = 0;
        }
        
        
    }
};
