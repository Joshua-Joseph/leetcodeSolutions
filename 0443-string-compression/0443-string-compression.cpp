class Solution {
public:
    int compress(vector<char>& chars) {
        int len=0;
        for(int j=0; j<chars.size(); j++){
            int k=j+1;
            while(k!=chars.size() and chars[k]==chars[j]) k++;
            if((k-j)==1){
                chars[len] = chars[j];
                len++;
            }
            else{
                if(k-j>9){
                    chars[len] = chars[j];
                    len++;
                    string num = to_string(k-j);
                    for(int i=0; i < num.length(); i++){
                        chars[len] = num.at(i);
                        len++;
                    }
                }
                else{
                    chars[len] = chars[j];
                    len++;
                    chars[len] = '0' + (k-j);
                    len++;
                } 
            }
            j=k-1;
        }
        return len;
    }
};