class Solution {
public:
    bool searchMatrix(vector<vector<int>>& m, int t) {
        int row = m.size();
        int col = m[0].size();
        int s = 0;
        int e = (row*col) - 1;
        int mid = s + (e-s)/2;
        while(s<=e){
            int element = m[mid/col][mid%col];
            if(t==element){
                return 1;
            }
            else if(t>element){
                s = mid + 1;
            }else{
                e = mid - 1;
            }
            mid = s + (e-s)/2;
        }
        return 0;
    }
};