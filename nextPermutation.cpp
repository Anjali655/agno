class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int ind = -1;

        // Step 1: find the Dip (first element from the last which is smaller than the next)
        for(int i = n - 2; i >= 0; i--) {
            if(nums[i] < nums[i+1]) {
                ind = i;
                break;
            }
        }

        // Step 2: if no dip found -> array is in decreasing order -> reverse to smallest
        if(ind == -1) {
            reverse(nums.begin(), nums.end());
            return;  // we’re done here
        }

        // Step 3: from right till ind, find element just larger than nums[ind] & swap
        for(int i = n - 1; i > ind; i--) {
            if(nums[i] > nums[ind]) {
                swap(nums[i], nums[ind]);
                break;
            }
        }

        // Step 4: reverse suffix to get smallest order after ind
        reverse(nums.begin() + ind + 1, nums.end());
    }
};
