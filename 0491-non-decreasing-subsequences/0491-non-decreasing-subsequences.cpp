class Solution {
public:
    void solve(vector<int>& nums, set<vector<int>> &ans, vector<int> &res, int i){
        if(i==nums.size()){
            return;
        }
        if(res.size()==0){
            //include
            res.push_back(nums[i]);
            solve(nums, ans, res, i+1);
            //exclude
            res.pop_back();
            solve(nums, ans, res, i+1);
        }
        else{
            if(nums[i]>=res[res.size()-1]){
                //include
                res.push_back(nums[i]);
                ans.insert(res);
                solve(nums, ans, res, i+1);
                //exclude
                res.pop_back();
                solve(nums, ans, res, i+1);
            }
            else{
                //exclude
                solve(nums, ans, res, i+1);
            }
        }
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        set<vector<int>> ans;
        vector<int> res;
        solve(nums, ans, res, 0);
        vector<vector<int>> finalAns;
        for(auto it = ans.begin(); it!=ans.end(); it++){
            finalAns.push_back(*it);
        }
        return finalAns;
    }
};