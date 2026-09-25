class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
            int value = nums[i];
            int digitSum = 0;

            while (value > 0) {
                digitSum += value % 10;
                value /= 10;
            }

            if (digitSum == i) {
                return i;
            }
        }

        return -1;
    }
};