class Solution {
public:
    static bool comparator (string a, string b)
    {
        return (a+b) > (b+a);
    }
    
    
    string largestNumber(vector<int>& nums) {
        vector<string> v;
        
        for (int i=0; i< nums.size(); i++)
            v.push_back(to_string(nums[i]));
            
        sort(v.begin(), v.end(), comparator);
        
        string s = "";
        
        for (int i=0; i< nums.size(); i++)
            s = s+v[i];
        
        while(s.size() > 1 && s[0] =='0')
            s.erase(s.begin());
            
        return s;    
        
    }
};
