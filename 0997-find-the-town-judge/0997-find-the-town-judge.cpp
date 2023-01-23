class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        map<int, vector<int>> town;
        map<int, vector<int>> reverseTown;
        for(int i=1; i<=n; i++){
            vector<int> temp;
            town[i] = temp;
            reverseTown[i] = temp;
        }
        for(int i=0; i<trust.size(); i++){
            town[trust[i][0]].push_back(trust[i][1]);
            reverseTown[trust[i][1]].push_back(trust[i][0]);
        }
        
        int ans = -1;
        for(auto i:town){
            if(town[i.first].size()==0 && reverseTown[i.first].size()==n-1){
                ans = i.first;
                break;
            }
        }
        return ans;
    }
};