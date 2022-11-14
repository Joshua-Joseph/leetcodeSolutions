class Solution {
public:
    int countGoodSubstrings(string s) {
        int cnt = 0;
        int i = 0;
        unordered_map<char,int> occur;
        for(int j=0; j<s.length(); j++){
            if(j-i+1==3){
                occur[s[j]]++;
                bool valid = true;
                for(auto k:occur){
                    // cout<<k.first<<" ";
                    if(k.second>1){
                        valid = false;
                        // cout<<k.first<<" "<<k.second<<" "<<s[j]<<endl;
                    }
                        
                }
                // cout<<endl;
                if(valid)
                    cnt++;
                occur[s[i]]--;
                i++;
            }
            else
                occur[s[j]]++;
        }
        return cnt;
    }
};