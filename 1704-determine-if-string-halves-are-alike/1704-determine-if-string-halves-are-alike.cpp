class Solution {
public:
    bool halvesAreAlike(string s) {
        int n = s.length();
        string s1 = "";
        string s2 = "";
        for(int i=0; i<n/2; i++){
            s1 += s[i];
        }
        for(int i=n/2; i<n; i++){
            s2 += s[i];
        }
        vector<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        unordered_map<char, bool> vow;
        for(auto i:vowels){
            vow[i] = true;
        }
        int cnt1 = 0;
        int cnt2 = 0;
        for(int i=0; i<s1.length(); i++){
            if(vow[s1[i]])
                cnt1++;
        }
        for(int i=0; i<s2.length(); i++){
            if(vow[s2[i]])
                cnt2++;
        }
        return cnt1==cnt2;
    }
};