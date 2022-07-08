// brute force solution
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        for(int i=0; i<n-1; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                if(nums[i]+nums[j]==target)
                    return vector<int>({i,j});
            }
        }
        return {-1};
    }
    
};

//O(n^2), O(1)

//two pointer solution (doesn't work properly)
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int start = 0;
        int end = numbers.size() -1;
        vector<int> ans;
        
        while(start<end)
        {
            int sum = numbers[start] + numbers[end];
            if(sum > target)
            {
                end--;
            }
            else if(sum < target)
            {
                start++;
            }
            else
            {
                ans.push_back(start );
                ans.push_back(end );
                break;
            }
        }
        return ans;
    }
};

//O(nlogn): search takes nlogn

//Using hash map solution
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //hash map solution
        vector<int> ret;
        int size = nums.size();
        int diff;
        unordered_map<int,int> m;
        
        for(int i=0; i<size; i++)
        {
            diff = target - nums[i];
            if(m.find(diff) != m.end() && m.find(diff)->second != i)
            {
                ret.push_back(i);
                ret.push_back(m.find(diff)->second);
                return ret;
            }
            m[nums[i]] = i;
        }
        return ret;
        
    }
};

//O(n)
