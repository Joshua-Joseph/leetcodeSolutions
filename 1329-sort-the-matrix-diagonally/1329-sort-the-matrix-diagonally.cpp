class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        vector<int> ans;
        int i = mat.size()-1;
        int j = 0;
        while(i>=0 and i<mat.size() and j>=0 and j<mat[0].size()){
            int m = i;
            int n = j;
            while(i>=0 and i<mat.size() and j>=0 and j<mat[0].size()){
                // cout<<mat[i][j]<<" ";
                ans.push_back(mat[i][j]);
                i+=1;
                j+=1;
            }
            i = m;
            j = n;
            sort(ans.begin(), ans.end());
            // cout<<"-> ";
            while(i>=0 and i<mat.size() and j>=0 and j<mat[0].size()){
                mat[i][j] = ans[0];
                // cout<<mat[i][j]<<" ";
                ans.erase(ans.begin());
                i+=1;
                j+=1;
            }
            if(m==0){
                i = m;
                j = n+1;
            }
            else{
                i = m-1;
                j = n;
            }
            // cout<<endl;
        }
        return mat;
    }
};