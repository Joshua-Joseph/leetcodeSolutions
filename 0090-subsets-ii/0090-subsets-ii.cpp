class Solution {
public:
    void solve(vector<vector<int>> &ans, vector<int>& nums, int ind, vector<int> res){
        // if(ind==nums.size()){
        //     cout<<res.size()<<endl;
            ans.push_back(res);
        //     return;
        // }
        // solve(ans, nums, ind+1, res);
        // res.push_back(nums[ind]);
        // solve(ans, nums, ind+1, res);
        
            for(int i=ind; i<nums.size(); i++){
                if(i!=ind and nums[i]==nums[i-1]){
                    continue;
                }
                res.push_back(nums[i]);
                solve(ans, nums, i+1, res);
                res.pop_back();
                
            }
        // res.pop_back();
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> res;
        sort(nums.begin(), nums.end());
        solve(ans, nums, 0, res);
        return ans;
    }
};