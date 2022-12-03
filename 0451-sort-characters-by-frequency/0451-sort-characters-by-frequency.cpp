class Solution {
public:
    void reverseString(string &s){
        int i = 0;
        int j = s.length()-1;
        while(i<j){
            swap(s[i], s[j]);
            i++;
            j--;
        }
        return;
    }
    string frequencySort(string s) {
        unordered_map<char, int> freq;
        for(auto i:s)
            freq[i]++;
        map<int, vector<char>> reverse;
        for(auto i:freq)
            reverse[i.second].push_back(i.first);
        string ans = "";
        for(auto i:reverse){
            for(auto j:i.second){
                string mid = "";
                for(int k=0; k<i.first; k++)
                    mid+=j;
                ans+=mid;
            }
        }
        reverseString(ans);
        return ans;
    }
};