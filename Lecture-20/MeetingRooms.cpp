// MeetingRooms.cpp
// Given an array of meeting time intervals
// intervals where intervals[i] = [starti, endi], return the minimum number of conference rooms required.
// Example 1:
// Input: intervals = [[0,30],[5,10],[15,20]]
// Output: 2
// Example 2:
// Input: intervals = [[7,10],[2,4]]
// Output: 1
// Constraints:
// 1 <= intervals.length <= 104
// 0 <= starti < endi <= 106
class Solution {
public:
	static bool compare(vector<int> a, vector<int> b) {
		return a[0] == b[0] ? a[1] < b[1] : a[0] < b[0];
	}

	int minMeetingRooms(vector<vector<int>>& intervals) {
		priority_queue<int, vector<int>, greater<int> > q;

		sort(intervals.begin(), intervals.end(), compare);
		for (auto data : intervals) {
			cout << data[0] << " " << data[1] << endl;
		}

		// start the first meeting
		q.push(intervals[0][1]); // Add the end time of meeting[0]
		for (int i = 1 ; i < intervals.size(); i++) {
			int new_meeting_st = intervals[i][0];
			int new_meeting_et = intervals[i][1];
			int purani_meeting_et = q.top();
			if (purani_meeting_et <= new_meeting_st) {
				q.pop();
				q.push(new_meeting_et);
			}
			else {
				q.push(new_meeting_et);
			}
		}

		return q.size();
	}
};
// [[0,30],[10,15],[10,11],[10,13],[10,12],[5,10],[15,20]]









