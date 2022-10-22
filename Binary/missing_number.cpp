class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int result = n;
        int i=0;
        
        for(int num:nums)
        {
            result = result ^ num;
            result = result ^ i;
            i++;
        }
        return result;
    }
};
