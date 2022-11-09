class Solution {
public:
//     void solve(vector<int>& nums, int index, vector<vector<int>>& ans){
        
//         if(index>=nums.size()){
//             ans.push_back(nums);
//             return ;
//         }
        
//         for(int j = index; j<nums.size(); j++){
//             swap(nums[index], nums[j]);
//             solve(nums, index+1, ans);
//             swap(nums[index], nums[j]);
//         }
        
        
//     }
    
//     vector<vector<int>> permute(vector<int>& nums) {
        
//         vector<vector<int>> ans;
//         solve(nums, 0, ans);
//         return ans;
        
//     }
    void solve(vector<int>& nums, int index, vector<vector<int>>& ans, 
               unordered_map<int, bool> &check, vector<int> res){
        if(index>=nums.size()){
            ans.push_back(res);
            return ;
        }
        for(int i=0; i<nums.size(); i++){
            if(!check[nums[i]]){
                check[nums[i]]=true;
                res.push_back(nums[i]);
                solve(nums, index+1, ans, check, res);
                res.pop_back();
                check[nums[i]]=false;
            }
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        unordered_map<int, bool> check;
        vector<vector<int>> ans;
        vector<int> res;
        solve(nums, 0, ans, check, res);
        return ans; 
    }
};