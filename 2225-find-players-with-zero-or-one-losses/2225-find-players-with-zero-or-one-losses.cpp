class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int, int> cnt;
        for(auto i:matches){
            cnt[i[0]];
            cnt[i[1]]++;
        }
        vector<vector<int>> ans(2);
        for(auto i:cnt){
            if(i.second==0)
                ans[0].push_back(i.first);
            if(i.second==1)
                ans[1].push_back(i.first);
        }
        sort(ans[0].begin(), ans[0].end());
        sort(ans[1].begin(), ans[1].end());
        // for(auto i:ans){
        //     sort(i.begin(), i.end());
        // }
        return ans;
    }
};