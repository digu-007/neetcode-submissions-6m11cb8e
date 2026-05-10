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
    bool canAttendMeetings(vector<Interval>& a) {
        sort(a.begin(), a.end(), [](auto &x, auto &y) {
            return x.start < y.start;
        });
        int prev = -1;
        for (auto &x: a) {
            if (x.start < prev) return false;
            prev = x.end;
        }
        return true;
    }
};
