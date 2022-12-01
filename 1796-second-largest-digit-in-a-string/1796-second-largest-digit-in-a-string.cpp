class Solution {
public:
    int secondHighest(string s) {
        set<int> val;
        for(int i=0; i<s.length(); i++){
            if(s[i]-'0'>=0 and s[i]-'0'<=9)
                val.insert(s[i]-'0');
        }
        if(val.size()<=1)
            return -1;
        set<int, greater<int> >::iterator itr = val.end();
        for(int i=0; i<2; i++)
            itr--;   
        return *itr; 
        
    }
};