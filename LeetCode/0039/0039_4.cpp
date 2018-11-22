
#include <vector>
#include <iostream>
#include <algorithm>


// my implements of backtrace

static void helper(const std::vector<int>& cand,
                   int target,
                   std::vector<std::vector<int>>& ans,
                   std::vector<int>& combi,
                   int sum,
                   int pos) {

    if (sum > target) {
        return;
    }
    else if (sum == target) {
        ans.push_back(combi);
        return;
    }

    for (size_t i=pos; i<cand.size(); ++i) {
        combi.push_back(cand[i]);
        helper(cand, target, ans, combi, sum+cand[i], i);
        combi.pop_back();
    }
}

std::vector<std::vector<int>> combinationSum(std::vector<int>& cand, int target) {
    std::sort(cand.begin(), cand.end());
    std::vector<std::vector<int>> ans;
    std::vector<int> combi;
    helper(cand, target, ans, combi, 0, 0);
    return ans;
}

int main(int argc, char* argv[]) {

    std::vector<int> candidates{2,3,5};
    int target = 8;

    std::cout << "candidates: ";
    for (int n : candidates) {
        std::cout << n << " ";
    }
    std::cout << std::endl << "target: " << target << std::endl;


    //    Solution sln;
    std::vector<std::vector<int>> ans = combinationSum(candidates, target);

    std::cout << "result:" << std::endl;
    for (const auto& combi : ans) {
        for (int n : combi) {
            std::cout << n << " ";
        }
        std::cout << std::endl;
    }

    std::cout << "answer count(): " << ans.size() << std::endl;

    return 0;
}
