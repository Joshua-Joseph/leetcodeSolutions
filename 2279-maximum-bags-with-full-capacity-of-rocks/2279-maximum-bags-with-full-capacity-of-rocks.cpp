class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        vector<int> diff;
        for(int i=0; i<capacity.size(); i++){
            diff.push_back(capacity[i] - rocks[i]);
        }
        sort(diff.begin(), diff.end());
        int i=0;
        while(additionalRocks>0 and i<diff.size()){
            if(diff[i]>0 and diff[i]<=additionalRocks){
                additionalRocks-=diff[i];
                diff[i] = 0;
            }
            i++;
        }
        int cnt = 0;
        for(int i=0; i<diff.size(); i++){
            if(diff[i]==0)
                cnt++;
        }
        return cnt;
    }
};