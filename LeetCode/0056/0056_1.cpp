
#include <iostream>
#include <vector>

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
        std::vector<Interval> ans;

        return ans;
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
