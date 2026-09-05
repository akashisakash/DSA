class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        std::sort(nums.begin(),nums.end());
        std::vector<std::vector<int>>ans;
        int n=nums.size();
        if(n<4)return {};
        for(int i=0;i<n-3;++i){
            if((long long)nums[i]+nums[i+1]+nums[i+2]+nums[i+3]>target)break;
            if((long long)nums[i]+nums[n-1]+nums[n-2]+nums[n-3]<target)continue;
            for(int j=i+1;j<n-2;++j){
                if((long long)nums[i]+nums[j]+nums[j+1]+nums[j+2]>target)break;
                if((long long)nums[i]+nums[j]+nums[n-1]+nums[n-2]<target)continue;
                int l=j+1,r=n-1;
                while(l<r){
                    long long sum=(long long)nums[i]+nums[j]+nums[l]+nums[r];
                    if(sum==target){
                        ans.push_back({nums[i],nums[j],nums[l],nums[r]});
                        while(l<r&&nums[l]==nums[l+1])l++;
                    while(l<r&&nums[r]==nums[r-1])r--;
                        r--;
                    }
                    else if(sum<target){
                        l++;
                    }
                    else{
                        r--;
                    }
                }
                while(j<n-1&&nums[j+1]==nums[j])j++;
            }
            while(i<n-1&&nums[i+1]==nums[i])i++;
        }
        return ans;
    }
};