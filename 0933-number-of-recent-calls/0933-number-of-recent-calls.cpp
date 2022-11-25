class RecentCounter {
public:
    int t;
    vector<int> v;
    RecentCounter() {
        t = 0;   
    }
    
    int ping(int t) {
        v.push_back(t);
        int cnt = 0;
        for(auto i:v){
            if(i>=t-3000 and i<=t)
                cnt++;
        }
        return cnt;
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */