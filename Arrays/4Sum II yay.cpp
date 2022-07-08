class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int res=0;
        int size = nums1.size();
        unordered_map<int, int> m;
        int diff;
        
        for (int i = 0; i<size; i++)
        {
            for (int j=0; j< size; j++)
            {
                m[nums1[i]+nums2[j]]++;
            }
        }
        
        for (int k = 0; k<size; k++)
        {
            for(int l =0; l<size; l++)
            {
                diff = -nums3[k] - nums4[l];
                if (m.find(diff) != m.end())
                {
                   res = res+m.find(diff)->second;
                }
            }
        }
        return res;
    }
};
