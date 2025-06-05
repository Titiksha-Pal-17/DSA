class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        int low = 1;
        int high = n - 1;

        while (low < high) {
            int mid = (low + high) / 2;

            // Count how many numbers are less than or equal to mid
            int count = 0;
            for (int i = 0; i < n; i++) {
                if (nums[i] <= mid) {
                    count++;
                }
            }

            if (count > mid) {
                high = mid; // duplicate is in [low, mid]
            } else {
                low = mid + 1; // duplicate is in [mid + 1, high]
            }
        }

        return low;
    }
};