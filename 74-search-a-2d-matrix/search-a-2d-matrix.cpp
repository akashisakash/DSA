class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int i = 0, j = m * n - 1;
        while (i <= j) {
            int mid = i + (j - i) / 2;
            int mid_value = matrix[mid / n][mid % n];
            if (mid_value == target) {
                return true;
            } else if (mid_value > target) {
                j = mid - 1;
            } else {
                i = mid + 1;
            }
        }
        return false;
    }
};