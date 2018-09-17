
// 这个是leetcode中的solution

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        if (nums.size() < 3) {
            return -1;
        }

        std::sort(nums.begin(), nums.end());

        int diff = INT_MAX;
        int closest;

        for (int mid = 1; mid < (nums.size() - 1); mid++) {
            int left = 0;
            int right = nums.size() - 1;
            int currentTarget = target - nums[mid];

            while (left < mid && mid < right) {
                int sum = nums[left] + nums[right];

                if (sum == currentTarget) {
                    return target;
                }

                if (std::abs(sum - currentTarget) < diff) {
                    diff = std::abs(sum - currentTarget);
                    closest = sum + nums[mid];
                }

                if (sum > currentTarget) {
                    right--;
                } else {
                    left++;
                }

                //cout << nums[left] + nums[right] + nums[mid] << endl;
            }
        }

        return closest;
    }
};
