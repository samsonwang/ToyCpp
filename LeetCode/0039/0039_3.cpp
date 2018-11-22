
#include <vector>
#include <algorithm>
#include <iostream>

// backtracking alogrithm 回溯算法
// 这个解法来自于leetcode中的solution
class Solution {
public:
    std::vector<std::vector<int> > combinationSum(std::vector<int> &candidates, int target) {
        std::sort(candidates.begin(), candidates.end());
        std::vector<std::vector<int> > res;
        std::vector<int> combination;
        combinationSum(candidates, target, res, combination, 0);
        return res;
    }
private:
    void combinationSum(std::vector<int> &candidates,
                        int target,
                        std::vector<std::vector<int> > &res,
                        std::vector<int> &combination, int begin) {
        if (!target) {
            res.push_back(combination);
            return;
        }
        for (int i = begin; i != candidates.size() && target >= candidates[i]; ++i) {
            combination.push_back(candidates[i]);
            combinationSum(candidates, target - candidates[i], res, combination, i);
            combination.pop_back();
        }
    }
};


int main(int argc, char* argv[]) {

    std::vector<int> candidates{2,3,5};
    int target = 8;

    for (int n : candidates) {
        std::cout << n << " ";
    }

    std::cout << std::endl << target << std::endl;
    Solution sln;
    std::vector<std::vector<int>> ans = sln.combinationSum(candidates, target);

    for (const auto& combi : ans) {
        for (int n : combi) {
            std::cout << n << " ";
        }
        std::cout << std::endl;
    }

    std::cout << "ans size():" << ans.size();

    return 0;
}
