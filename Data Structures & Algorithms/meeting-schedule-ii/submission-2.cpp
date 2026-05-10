/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), [](auto &a, auto &b) {
            return a.start < b.start;
        });
        priority_queue<int, vector<int>, greater<int>> pq;
        for (auto &x: intervals) {
            if (pq.size() and x.start >= pq.top()) pq.pop();
            pq.push(x.end);
        }
        return pq.size();
    }
};
