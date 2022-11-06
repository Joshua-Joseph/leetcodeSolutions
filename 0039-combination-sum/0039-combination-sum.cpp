class Solution {
public:
    void solve(vector<vector<int>> &ans, vector<int>& candidates, vector<int> res, int target, int sum, int ind){
        if(sum==target){
            ans.push_back(res);
            return;
        }
        if(ind==candidates.size() or sum>target)
            return;
        solve(ans, candidates, res, target, sum, ind+1);
        res.push_back(candidates[ind]);
        solve(ans, candidates, res, target, sum+candidates[ind], ind);   
        return;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> res;
        int sum = 0;
        solve(ans, candidates, res, target, sum, 0);
        return ans;
    }
};