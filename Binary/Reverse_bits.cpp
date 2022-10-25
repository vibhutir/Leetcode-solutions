class Solution {
public:
    bool findifkthbitset(int i, uint32_t n)
    {
        if (((1 << (i-1)) & n) != 0) 
            return true;
        else 
            return false;
    
    }
                         
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans = 0;
        
        for (int i=1; i<=32; i++)
        {
            if(findifkthbitset(i,n))
            {
                ans  = (1<< (32-i)) | ans;
            }
        }
        
        return ans;
        
    }
};
