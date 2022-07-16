class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        func (ans, n, 0, 0, "");
        return ans;
    }
    
    void func(vector<string>&ans, int n, int open, int close, string curr)
    {
        //base case
        if(curr.length()==2*n)
        {
            ans.push_back(curr);
            return;
        }
        
        if(open<n)
        {
            func(ans, n, open+1, close, curr + '(');
        }
        
        if(close<open)
        {
            func(ans, n, open, close+1, curr +')');
        }
    }
};
