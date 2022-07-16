class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int result =0 ;
        int start = intervals[0][0];
        int end = intervals[0][1];
        
        
        for (auto i : intervals)
        {
            
            if(end > i[0])
            {
                result++;
                end = min(end, i[1]);
                
            }
            else
                end = i[1];
        }
        
        return result-1;
    }
};
