

// leetcode 4ms solution
// why this is faster

class Solution {
private:
    void combinate(vector<vector<int> > & res, vector<int> & pol, vector<int> &candidate, int target, int num){
        if(target == 0){
            sort(pol.begin(), pol.end());
            res.push_back(pol);
            return ;
        }
        if(target < 0)
            return ;
        for(int i = num + 1; i < candidate.size(); ++i){
            if(i > num + 1 && candidate[i] == candidate[i - 1])
                continue ;
            if(candidate[i] > target)
                return;
            pol.push_back(candidate[i]);
            combinate(res, pol, candidate, target - candidate[i], i);
            pol.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int> > res;
        vector<int> pol;
        std::sort(candidates.begin(), candidates.end());
        for(int i = 0; i < candidates.size(); ++i){
            if(candidates[i] > target)
                break;
            if(i > 0 && candidates[i] == candidates[i - 1])
                continue ;
            //pol.clear();
            pol.push_back(candidates[i]);
            combinate(res, pol, candidates, target - candidates[i], i);
            pol.pop_back();
        }
        return res;
    }
};
