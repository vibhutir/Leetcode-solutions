//using quickselect: O(n)

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        
        int number = quickselect(nums,0, n-1, n-k);
        
        return number;
        
    }
    
    
private:
    int quickselect(vector<int>& nums, int start, int end, int K)
    {
        if(start==end)
            return nums[start];
        int P = partition(nums, start, end);
        
        if (P==K)
            return nums[P];
        if (P<K)
            return quickselect(nums, P+1, end, K);
        else
            return quickselect(nums, start, P-1, K);
    }
    
    int partition(vector<int>& nums, int start, int end)
    {
        int r_index = start + rand() % (end-start);
        swap(nums[r_index], nums[end]);
        
        int pivot = nums[end];
        
        int i= start;
        
        for(int j=start; j<end; j++)
        {
            if(nums[j] < pivot)
            {
                swap(nums[i], nums[j]);
                i++;
            }
        }
        
        swap(nums[end], nums[i]);
        return i;
    }
};
