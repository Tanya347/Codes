
/********************************************************************** QUESTION **************************************************************************************/

/*

Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

You may assume that the intervals were initially sorted according to their start times.

Example 1:

Given intervals [1,3],[6,9] insert and merge [2,5] would result in [1,5],[6,9].

Example 2:

Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] would result in [1,2],[3,10],[12,16].

This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].

Make sure the returned intervals are also sorted.


*/

/********************************************************************** ANSWER **************************************************************************************/


/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
 
bool sortByStart(Interval a, Interval b) {
    return a.start < b.start;
} 

vector<Interval> Solution::insert(vector<Interval> &intervals, Interval newInterval) {
    
    // insert new interval into array
    intervals.push_back(newInterval);
    
    // sort the interval based on start
    sort(intervals.begin(), intervals.end(), sortByStart);
    
    vector<Interval> ans;
    
    // push the first element into the array and then perform operations based on upper bound 
    // of the last element that was inserted into answer
    ans.push_back(intervals[0]);
    
    for(int i = 1; i < intervals.size(); i++) {
        
        // if the current interval overlaps with the last interval present in the ans array
        // then merge by making the end of the last interval as whatever upper bound is greater
        if(intervals[i].start <= ans[ans.size() - 1].end) {
            ans[ans.size() - 1].end = max(ans[ans.size() - 1].end, intervals[i].end);
        }
        
        // if disjoint interval just push into answer array
        else {
            ans.push_back(intervals[i]);            
        }
    }
    
    return ans;
}
