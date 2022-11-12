class Solution {
public:
    string getPermutation(int n, int k) {
        int fact = 1;
        vector<int> nums;
        for(int i=1; i<n; i++){
            fact = fact*i;
            nums.push_back(i);
        }
        nums.push_back(n);
        string ans = "";
        k = k-1;
        while (true){
            ans += to_string(nums[k/fact]);
            nums.erase(nums.begin()+(k/fact));
            if(nums.size()==0)
                break;
            k = k%fact;
            fact = fact/nums.size();
        }
        return ans;
    }
};





// class Solution {
// public:
//     void getAll(vector<string> &ans, string s, int i){
//         if(i==s.length()){
//             ans.push_back(s);
//             return;
//         }
        
//         for(int j=i; j<s.length(); j++){
//             swap(s[i], s[j]);
//             getAll(ans, s, i+1);
//             swap(s[i], s[j]);
//         }
//     }
    
//     string getPermutation(int n, int k) {
//         string s = "";
//         char N = '0'+n;
//         for(char c = '1'; c<=N; c++){
//             s+=c;
//         }
//         vector<string> ans;
//         getAll(ans, s, 0);
//         sort(ans.begin(), ans.end());
//         // for(int i=0; i<ans.size(); i++){
//         //     cout<<i<<" "<<ans[i]<<endl;
//         // }
//         return ans[k-1];
//     }
// };