// MeetingRooms - 1.cpp
// Given an array of meeting time intervals where
// intervals[i] = [starti, endi], determine if a person could attend all meetings.
// Example 1:
// Input: intervals = [[0,30],[5,10],[15,20]]
// Output: false
// Example 2:
// Input: intervals = [[7,10],[2,4]]
// Output: true
// Constraints:
// 0 <= intervals.length <= 10^4
// intervals[i].length == 2
// 0 <= starti < endi <= 10^6

class Solution {
public:
  static bool compare(vector<int> a, vector<int> b) {
    return a[0] == b[0] ? a[1] < b[1] : a[0] < b[0];
  }
  bool canAttendMeetings(vector<vector<int>>& intervals) {
    if (intervals.size() == 0) return true;
    sort(intervals.begin(), intervals.end(), compare);
    for (auto data : intervals) {
      cout << data[0] << " " << data[1] << endl;
    }

    // start the first meeting
    int purani_meeting_et = intervals[0][1];
    for (int i = 1 ; i < intervals.size(); i++) {
      int new_meeting_st = intervals[i][0];
      int new_meeting_et = intervals[i][1];
      if (new_meeting_st >= purani_meeting_et) {
        purani_meeting_et = new_meeting_et;
      }
      else {
        return false;
      }
    }

    return true;
  }
};