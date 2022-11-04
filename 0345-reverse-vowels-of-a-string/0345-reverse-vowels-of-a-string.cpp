class Solution {
public:
    string reverseVowels(string s) {
        vector<int> index;
        stack<char> st;
        for(int i=0; i<s.size(); i++){
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u' ||
               s[i]=='A' || s[i]=='E' || s[i]=='I' || s[i]=='O' || s[i]=='U'){
                st.push(s[i]);
                index.push_back(i);
            }
        }
        
        for(int i=0; i<index.size(); i++){
            s[index[i]] = st.top();
            st.pop();
        }
        return s;
    }
};