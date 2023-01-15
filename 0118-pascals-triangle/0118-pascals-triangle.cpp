class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for(int i=0; i<numRows; i++){
            vector<int> a(i+1, 0);
            for(int j=0; j<a.size(); j++){
                if(j==0 or j==a.size()-1){
                    a[j] = 1;
                }
                else{
                    a[j] = ans[i-1][j-1] + ans[i-1][j];
                }
            }
            ans.push_back(a);
        }
        return ans;
    }
};