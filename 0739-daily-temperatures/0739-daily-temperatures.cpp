class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperature) {
        vector<int>ans;
        int n = temperature.size();
        ans.push_back(0);
        stack<int>s;
        s.push(n-1);

        for(int i=n-2;i>=0;i--){
            while(s.empty()==false && temperature[s.top()]<=temperature[i]){
                s.pop();    
            }
            if(s.empty()==true){
                ans.push_back(0);
            }
            else{
                ans.push_back(s.top()-i);
            }
            s.push(i);
        }

        //since we traversed the array from right end
        reverse(ans.begin(),ans.end());
        return ans;
    }
};