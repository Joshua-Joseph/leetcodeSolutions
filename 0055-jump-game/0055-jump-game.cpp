class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size(), nZero = 0;
        vector<int> temp;
        bool ans = false;

        if(n == 1){
            return true;
        }
        //if there is no element zero in the array, then definitely we can reach the last index
        for(int i = 0; i < n-1; i++){
            if(nums[i] == 0){
                temp.push_back(i);
                nZero++;
            }
        }       
        if(nZero == 0){
            return true;
        }
        
        //if 0s are present in the array, then check if it is possible to cross each and every 0. We can cross a 0 if atleast one element before this 0 has the value greater than it's distance from this 0
        while(nZero){
            int counter = 1, j;
            for(j = temp[nZero-1]-1; j>=0; j--){
                    if(counter < nums[j]){
                        ans = true;
                        break;
                    }
                    counter++;
            }
            if(j < 0){
                return false;
            }
            nZero--;
        }

        return ans;
        
    }
};