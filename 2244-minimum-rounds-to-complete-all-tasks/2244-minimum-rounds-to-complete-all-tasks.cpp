class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        int rounds = 0;
        unordered_map<int, int> taskCnt;
        for(auto i:tasks){
            taskCnt[i]++;
        }
        for(auto i:taskCnt){
            // cout<<i.first<<" "<<i.second<<" ";
            if(i.second<2){
                return -1;
            }
            while(i.second-3>=2){
                i.second = i.second-3;
                rounds++;
            }
            // cout<<i.second<<" ";
            while(i.second-2>=0){
                i.second = i.second-2;
                rounds++;
            }
            // cout<<i.second<<endl;
        }
        return rounds;
    }
};