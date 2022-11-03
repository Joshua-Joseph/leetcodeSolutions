class Solution {
public:
    string sortSentence(string st) {
        vector<string> sent;
        string res="";
        for(int i=0; i<st.size(); i++){
            if(st[i]==' '){
                sent.push_back(res);
                res="";
            }
            else{
                res+=st[i];
            }
        }
        sent.push_back(res);
        map<int,string> order;
        for(auto s:sent){
            int n = s[s.length()-1]-48;
            s.pop_back();
            order[n] = s;
        }
        string ans = "";
        for(auto s:order){
            ans+=s.second;
            ans+=" ";
        }
        ans.pop_back();
        return ans;
    }
};