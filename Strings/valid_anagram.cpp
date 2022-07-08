class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> m;
        int size = t.length();
        int size1 = s.length();
        
        if(size != size1)
            return false;
        
        for(int i=0; i<size; i++)
        {
            m[s[i]]++;
        }
        
        for (int i=0; i<size; i++)
        {
            m[t[i]]--;
        }
        
        for(auto count: m)
        {
            if(count.second != 0)
                return false;
        }
        return true;
    }
};
