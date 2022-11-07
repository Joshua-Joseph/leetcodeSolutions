class Solution {
public:
    void solve(vector<vector<int>> &ans, vector<int>& candidates, vector<int> res, int target, int sum, int ind){
        if(sum==target){
            ans.push_back(res);
            return;
        }
        if(ind==candidates.size() or sum>target)
            return;
        
        res.push_back(candidates[ind]);
        solve(ans, candidates, res, target, sum+candidates[ind], ind+1);
        res.pop_back();
        
        for(int i=ind+1; i<candidates.size(); i++){
            if(candidates[i]!=candidates[i-1]){
                res.push_back(candidates[i]);
                solve(ans, candidates, res, target, sum+candidates[i], i+1);
                res.pop_back();
            }
        }  
        return;
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> res;
        int sum = 0;
        sort(candidates.begin(), candidates.end());
        solve(ans, candidates, res, target, sum, 0);
        return ans;
    }
};