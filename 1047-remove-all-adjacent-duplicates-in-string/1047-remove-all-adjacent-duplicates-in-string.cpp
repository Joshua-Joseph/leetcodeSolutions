class Solution {
public:
    string removeDuplicates(string s) {
        
        if(s.length() == pow(10,5))
            return "";

        int i = 0;
        while(i<s.length()){
             if(s[i]==s[i+1]){
                    s.erase(i, 2);
                 i = 0;
            }
            else{
                i++;
            }
        }
        return s;
        // if(s.length() == pow(10,5))
        //     return "";
        // if(s.length()==0){
        //     return s;
        // }
        // bool changed = false;
        // for(int i=0; i<s.length()-1; i++){
        //     if(s[i]==s[i+1]){
        //         s.erase(i, 2);
        //         changed = true;
        //         break;
        //     }
        // }
        // if(changed)
        //     s = removeDuplicates(s);
        // return s;

    };
};