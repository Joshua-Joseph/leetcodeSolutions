class Solution {
public:
    vector<string> cellsInRange(string s) {
        vector<string> ans;
        char startLetter = s[0];
        char startNum = s[1];
        char endLetter = s[3];
        char endNum = s[4];
        while(startLetter<=endLetter){
            cout<<startLetter;
            while(startNum<=endNum){
                string res = "";
                res+=startLetter;
                res+=startNum;
                ans.push_back(res);
                startNum+=1;
            }
            startNum=s[1];
            startLetter+=1;
        }
        return ans;
    }
};