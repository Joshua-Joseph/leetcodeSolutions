class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        vector<int> res;
        for(int i=0; i<queries.size(); i++){
            priority_queue<int> pq;
            int sum=queries[i], cur_sum=0, c=0;
            for(auto& x: nums){
                if(cur_sum+x<=sum){
                    c++;
                    cur_sum+=x;
                    pq.push(x);
                    continue;
                }
                if(!pq.empty() && x<pq.top()){
                    cur_sum-=pq.top();
                    pq.pop();
                    pq.push(x);
                    cur_sum+=x;
                }
            }
            res.push_back(pq.size());
        }
        return res;
    }
};