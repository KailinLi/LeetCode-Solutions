/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> answer;
        if (intervals.size() == 0) {
            answer.push_back(newInterval);
            return answer;
        }
        int finish = 0;
        int start = 1;
        int indexAnswer = 0;
        auto indexOrigin = intervals.begin();
        while (indexOrigin != intervals.end()) {
            if (finish == 0) {
                if (start == 1) {
                    if (newInterval.start <= indexOrigin->start) {
                        Interval get(newInterval.start, -1);
                        answer.push_back(get);
                        if (newInterval.end >= indexOrigin->start) {
                            start = 0;
                        }
                        finish = 1;
                    }
                    else {
                        Interval get(indexOrigin->start, -1);
                        answer.push_back(get);
                        start = 0;
                    }
                }
                else {
                    if (newInterval.start <= indexOrigin->end) {
                        finish = 1;
                        start = 1;
                        if (newInterval.end >= indexOrigin->end) {
                            indexOrigin++;
                        }
                    }
                    else {
                        answer[indexAnswer].end = indexOrigin->end;
                        indexOrigin++;
                        indexAnswer++;
                        start = 1;
                    }
                }
            }
            else if (finish == 1) {
                if (start == 1) {
                    if (newInterval.end < indexOrigin->start) {
                        answer[indexAnswer].end = newInterval.end;
                        indexAnswer++;
                        finish = 2;
                    }
                    else {
                        start = 0;
                    }
                }
                else {
                    if (newInterval.end <= indexOrigin->end) {
                        answer[indexAnswer].end = indexOrigin->end;
                        start = 1;
                        finish = 2;
                        indexAnswer++;
                        indexOrigin++;
                    }
                    else {
                        indexOrigin++;
                        start = 1;
                    }
                }
            }
            else {
                if (start == 1) {
                    Interval get(indexOrigin->start, -1);
                    answer.push_back(get);
                    start = 0;
                }
                else {
                    answer[indexAnswer].end = indexOrigin->end;
                    indexOrigin++;
                    indexAnswer++;
                    start = 1;
                }
            }
        }
        if (finish == 0) {
            Interval get = newInterval;
            answer.push_back(get);
        }
        else if (finish == 1) {
            answer[indexAnswer].end = newInterval.end;
        }
        return answer;
    }
};