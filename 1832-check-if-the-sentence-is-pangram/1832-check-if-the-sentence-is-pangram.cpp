class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<int> count(26,0);
        for(int i=0; i<sentence.length(); i++){
            count[sentence[i]-'a']+=1;
        }
        for(auto i:count){
            if(i==0)
                return 0;
        }
        return 1;
    }
};