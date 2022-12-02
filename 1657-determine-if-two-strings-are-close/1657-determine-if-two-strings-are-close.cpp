class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.length()!=word2.length())
            return false;
        //
        unordered_map<char, int> w1;
        unordered_map<char, bool> w11;
        unordered_map<char, bool> w22;
        for(int i=0; i<word1.length(); i++){
            w1[word1[i]]++;
            w11[word1[i]] = true;
        }
        vector<int> v1;
        for(auto i:w1){
            v1.push_back(i.second);
        }
        w1.clear();
        for(int i=0; i<word2.length(); i++){
            w1[word2[i]]++;
            w22[word2[i]] = true;
        }
        vector<int> v2;
        for(auto i:w1){
            v2.push_back(i.second);
        }
        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());
        //
        
        if(v1.size()==v2.size()){
            for(int i=0; i<v1.size(); i++){
                if(v1[i]!=v2[i])
                    return false;
            }
        }
        else{
            return false;
        }
        if(w11.size()==w22.size()){
            for(auto i:w11){
                if(i.second!=w22[i.first]){
                    return false;
                }
            }
        }
        else{
            return false;
        }
        return true;
    }
};