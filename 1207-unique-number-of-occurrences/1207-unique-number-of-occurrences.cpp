class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, vector<int>> cnt;
        unordered_map<int, int> cnt2;
        for(auto i:arr){
            cnt2[i]++;
        }
        for(auto i:cnt2){
            cnt[i.second].push_back(i.first);
        }
        for(auto i:cnt){
            if(i.second.size()>1)
                return false;
        }
        return true;
    }
};