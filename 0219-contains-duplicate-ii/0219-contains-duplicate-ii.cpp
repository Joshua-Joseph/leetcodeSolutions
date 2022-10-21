class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int, int> count;
        bool yes = false;
        int num;
        for(int i=0; i<nums.size(); i++){
            count[nums[i]]++;
            if(count[nums[i]]>1){
                yes = true;
                num = nums[i];
            }
            if(yes){
                break;
            }
        }
        if(yes){
            vector<int> pos;
            for(int i=0; i<nums.size(); i++){
                if(nums[i]==num){
                    pos.push_back(i);
                }
            }
            for(int i=0; i<pos.size()-1; i++){
                if(abs(pos[i]-pos[i+1])<=k){
                    cout<<pos[i]<<pos[i+1];
                    return true;
                }
            }
            return false;
        }
        else{
            return false;
        }   
    }
};