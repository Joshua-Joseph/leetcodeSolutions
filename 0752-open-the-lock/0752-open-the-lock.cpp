class Solution {
public:
    vector<string> findChildren(string s){
        vector<string> res;
        for(int i=0; i<4; i++){
            string copy = s;
            int next = (s[i]-48+1)%10;
            char n = next+'0';
            copy[i] = n;
            res.push_back(copy);
            copy = s;
            int prev = (((s[i]-48)-1)+10)%10;
            char p = prev+'0';
            copy[i] = p;
            res.push_back(copy);
        }
        return res;
    }
    
    int openLock(vector<string>& deadends, string target) {
        queue<string> q;
        q.push("0000");
        unordered_map<string, bool> vis;
        for(auto i:deadends){
            vis[i] = true;
        }
        if(vis["0000"]){
            return -1;
        }
        vis["0000"] = true;
        int cnt = 0;
        while(!q.empty()){
            int n = q.size();
            for(int i=0; i<n; i++){
                string s = q.front();
                if(s==target){
                    return cnt;
                }
                q.pop();
                vector<string> res = findChildren(s);
                for(auto st: res){
                    if(!vis[st]){
                        vis[st]=true;
                        q.push(st);
                    }
                }
            }
            if(!q.empty()){
                cnt++;
            }
        }        
        return -1;
    }
};