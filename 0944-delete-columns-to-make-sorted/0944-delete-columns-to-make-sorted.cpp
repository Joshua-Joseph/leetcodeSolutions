class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int cnt = 0;
        for(int i=0; i<strs[0].length(); i++){
            for(int j=0; j<strs.size()-1; j++){
                if(strs[j][i]-97>strs[j+1][i]-97){
                    cnt++;
                    break;
                }
            }
        }
        return cnt;
    }
};