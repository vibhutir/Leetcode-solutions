class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<char> st;
        int max = 0;
        
        int start = 0;
        int end = 0;
        
        while (start < s.size())
        {
            auto it = st.find(s[start]); //see if start element already exists in set
            
            if (it == st.end())
            {
                if (start-end+1 > max)
                    max = start-end+1;
                st.insert(s[start]);
                start++;
            }
            
            else
            {
                st.erase(s[end]);
                end++;
            }
        }
        
        
        return max;
    }
};
