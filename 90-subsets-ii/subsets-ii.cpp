class Solution {
public:
    void generateSubset(int ind, vector<int>& arr, vector<int>& ds, vector<vector<int>>& res) {
        res.push_back(ds);
        for(int i = ind; i < arr.size(); i++) {
            if(i > ind && arr[i] == arr[i - 1]) continue;
            ds.push_back(arr[i]);
            generateSubset(i + 1, arr, ds, res);
            ds.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> ds;
        generateSubset(0, nums, ds, res);
        return res;
    }
};