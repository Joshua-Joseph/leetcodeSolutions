class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> pq;
        for(auto i:piles)
            pq.push(i);
        while(k){
            int top = pq.top();
            pq.pop();
            top = top - floor(top/2);
            pq.push(top);
            k--;
        }
        int tot = 0;
        while(pq.size()>0){
            tot += pq.top();
            pq.pop();
        }
        return tot;
    }
};