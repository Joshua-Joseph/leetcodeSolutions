class Solution {
public:
    bool isPali(string s){
        if(s.size()==0){
            return false;
        }
        int i = 0;
        int j = s.size()-1;
        while(i<j){
            if(s[i]!=s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
    
    void solve(vector<vector<string>> &ans, vector<string> res, string s, int ind){
        if(ind==s.size()){
            ans.push_back(res);
            return;
        }
        for(int i=ind; i<s.size(); i++){
            if(isPali(s.substr(ind, i-ind+1))){
                res.push_back(s.substr(ind, i-ind+1));
                solve(ans, res, s, i+1);
                res.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> res;
        solve(ans, res, s, 0);
        return ans;
    }
};