class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1.0;
        long long int N;
        if(n<0)
            N = -1.0*n;
        else
            N = n;
        while(N>0){
            if(N%2==0){
                x = x*x;
                N = N/2;
            }
            else{
                ans = ans*x;
                N = N-1;
            }
        }
        // ans = ans*x;
        if(n<0)
            ans = 1/ans;
        return ans;
    }
};