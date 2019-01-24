
#include <iostream>
#include <vector>
#include <algorithm>

#include "../../shared/stream.h"

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}

    friend std::ostream& operator<< (std::ostream& os,
                                     const Interval& interval) {
        os << '[' << interval.start << ',' << interval.end << ']';
        return os;
    }
};

class Solution {
public:
    std::vector<Interval> merge(std::vector<Interval>& intervals) {
        if (intervals.size() <= 1) {
            return intervals;
        }

        std::vector<Interval> ans;
        std::sort(intervals.begin(), intervals.end(),
                  Solution::intervalComp);
        ans.push_back(intervals.front());

        for (const auto& i : intervals) {
            if (i.start <= ans.back().end) {
                ans.back().end = std::max(i.end, ans.back().end);
            }
            else {
                ans.push_back(i);
            }
        }

        return ans;
    }

    static bool intervalComp(const Interval& a, const Interval& b) {
        return a.start < b.start;
    }
};

int main(int argc, char* argv[]) {
    std::vector<Interval> intervals;
    intervals.emplace_back(1,3);
    intervals.emplace_back(2,6);
    intervals.emplace_back(8,10);
    intervals.emplace_back(15,18);

    std::cout << "intervals: " << intervals << std::endl;

    std::vector<Interval> ans = Solution().merge(intervals);

    std::cout << "ans: " << ans << std::endl;

    return 0;
}
