class Solution {
public:
    bool detectCapitalUse(string word) {
        if(word.length()>1){
            //starting with small
            if(word[0]>='a' and word[0]<='z'){
                if(word.length()>1){
                    for(int i=1; i<word.length(); i++){
                        if(word[i]>='A' and word[i]<='Z') return false;
                    }
                }
            }
            // starting with capital
            else if(word[0]>='A' and word[0]<='Z'){
                if(word[1]>='a' and word[1]<='z'){ // following should be small
                    if(word.length()>2){
                        for(int i=2; i<word.length(); i++){
                            if(word[i]>='A' and word[i]<='Z') return false;
                        }
                    }
                }
                else{
                    if(word.length()>2){
                        for(int i=2; i<word.length(); i++){
                            if(word[i]>='a' and word[i]<='z') return false;
                        }
                    }
                }
            }
            
        }
        return true;
    }
};