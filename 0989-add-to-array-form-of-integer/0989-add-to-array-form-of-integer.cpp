class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        vector<int> K;
        while(k>0){
            K.insert(K.begin(), k%10);
            k=k/10;
        }
        if(K.size()>num.size()){
            vector<int> t;
            t=num;
            num=K;
            K=t;
        }
        int i=num.size()-1;
        int j=K.size()-1;
        int carry = 0;
        while(j>=0){
            int temp = num[i]+K[j]+carry;
            num[i] = temp%10;
            carry = temp/10;
            i--;
            j--;
        }
        // cout<<carry<<" "<<i<<endl;
        if(carry>0){
            if(i<0){
                num.insert(num.begin(), carry);
            }
            else{
                while(carry>0 && i>=0){
                    int temp = num[i]+carry;
                    num[i] = temp%10;
                    carry = temp/10;
                    i--;
                }
                if(carry>0) num.insert(num.begin(), carry);
            }
        }
        return num;
    }
};