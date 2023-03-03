class Solution {
public:
    int strStr(string haystack, string needle) {
        vector<int> occur;
        for(int i=0; i<haystack.length(); i++){
            if(haystack[i]==needle[0]) occur.push_back(i);
        }
        for(auto i:occur){
            int j=0;
            bool ans = true;
            for(int k=i; k<i+needle.length(); k++){
                if(haystack[k]!=needle[j]){
                    ans = false;
                    break;
                }
                j++;
            }
            if(ans) return i;
        }
        return -1;
    }
};