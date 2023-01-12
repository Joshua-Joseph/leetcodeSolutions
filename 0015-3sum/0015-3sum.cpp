// class Solution {
// public:
//     vector<vector<int>> threeSum(vector<int>& nums) {
//         vector<vector<int>> ans;
//         set<vector<int>> sv;
//         unordered_map<int, int> cnt;
//         for(int i=0; i<nums.size(); i++){
//             cnt[nums[i]]++;
//         }
//         sort(nums.begin(), nums.end());
//         int i=0;
//         int j=nums.size()-1;
//         while(i<j){
//             int diff = 0-(nums[i]+nums[j]);
//             // cout<<nums[i]<<"->"<<cnt[nums[i]]<<endl;
//             cnt[nums[i]]--;
//             cnt[nums[j]]--;
//             // cout<<nums[i]<<"->"<<cnt[nums[i]]<<endl;
//             if(cnt[diff]>0){
//                 // cout<<nums[i]<<" "<<nums[j]<<" "<<diff<<" "<<endl;
//                 vector<int> res;
//                 res.push_back(nums[i]);
//                 res.push_back(nums[j]);
//                 res.push_back(diff);
//                 sort(res.begin(), res.end());
//                 sv.insert(res);
//             }
//             cnt[nums[i]]++;
//             cnt[nums[j]]++;
//             if(nums[i]+nums[j]>=0)
//                 j--;
//             else
//                 i++;
//         }
//         for (auto it=sv.begin(); it!=sv.end(); it++) {
//             ans.push_back(*it);
//         }
//         return ans;
//     }
// };
// [-1,0,1,2,-1,-4,-2,-3,3,0,4]

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());
        int n=nums.size();
        set<vector<int>> s;
        for(int i=0;i<n;i++){
            int l=i+1;
            int h=n-1;
            while(l<h){
                int current=nums[i]+nums[l]+nums[h];
                if(current==0){
                    s.insert({nums[i],nums[l],nums[h]});
                    l++;
                    h--;
                }else if(current<0){
                    l++;
                }else{
                    h--;
                }
            }
        }
        vector<vector<int>>ans(s.begin(),s.end());
        return ans;
    }
};