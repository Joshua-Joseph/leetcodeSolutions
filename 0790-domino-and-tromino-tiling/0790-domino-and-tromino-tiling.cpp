class Solution {
public:
    int numTilings(int n) {
        int mod = pow(10,9)+7;
        
        if(n<=2) return n;
        vector<int> half(n+1,0);
        vector<int> full(n+1,0);
        full[1]=1;
        full[2]=2;
        half[2]=2;
        
        for(int i=3;i<=n;i++)
        {
            half[i]= (half[i-1] + (full[i-2]*2)%mod) %mod;
            full[i]= ((full[i-1] + full[i-2])%mod + half[i-1])%mod;
        } 
        
        return full[n]%mod;
        
    }
};