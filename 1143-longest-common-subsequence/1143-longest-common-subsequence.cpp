class Solution {
public:
    
    
    int longestCommonSubsequence(string &a, string &b) {
    short m[2][1000] = {};
    for (int i = 0; i < a.size(); ++i)
        for (int j = 0; j < b.size(); ++j)
            m[!(i % 2)][j + 1] = a[i] == b[j] ? m[i % 2][j] + 1 : max(m[i % 2][j + 1], m[!(i % 2)][j]);
    return m[a.size() % 2][b.size()];
}
//     void findsub(string text, unordered_map<string, int> &subsequence, int ind, string ans){
//         if(ind==text.length()){
//             subsequence[ans]++;
//             return;
//         }
//         findsub(text, subsequence, ind+1, ans);
//         ans+=text[ind];
//         findsub(text, subsequence, ind+1, ans);
//     }
    
//     int longestCommonSubsequence(string text1, string text2) {
//         unordered_map<string, int> subsequence;
//         string ans1 = "";
//         findsub(text1, subsequence, 0, ans1);
//         string ans2 = "";
//         findsub(text2, subsequence, 0, ans2);
//         vector<int> cnt;
//         for(auto i:subsequence){
//             if(i.second>1){
//                 cout<<i.first<<" ";
//                 cnt.push_back(i.first.length());
//             }
//         }
//         sort(cnt.begin(), cnt.end());
//         return cnt[cnt.size()-1];
//     }
};