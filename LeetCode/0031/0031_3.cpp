
// leetcode fastest
static int x = [](){
                   ios::sync_with_stdio(false);
                   cin.tie(nullptr);
                   return 0;
               }();

class Solution {
public:
    static void nextPermutation(vector<int>& nums) {
        int L = nums.size();
        int temp;
        if (L==0 or L==1)
            return;
        int store = 1;
        for(int i=L-1;i>0; i--) {
            if(nums[i-1]>=nums[i])
                store++;
            else
                break;
        }
        for(int i = 1; i <= store/2; i++){
            temp = nums[L-i];
            nums[L-i]=nums[L-store+i-1];
            nums[L-store+i-1]=temp;
        }
        if(L==store)
            return;
        int lead = nums[L-store-1];
        for(int i=1; i<=store; i++) {
            if(lead<nums[L-store-1+i]) {
                temp = nums[L-store-1];
                nums[L-store-1] = nums[L-store-1+i];
                nums[L-store-1+i] = temp;
                return;
            }
        }
    }
};
