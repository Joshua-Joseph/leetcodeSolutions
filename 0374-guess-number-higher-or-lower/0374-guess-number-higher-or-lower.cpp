/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    void binarySearch(int s, int e, int &ans){
        if(s>e){
            return;
        }
        int mid = s + (e-s)/2;
        if(guess(mid)==0){
            ans = mid;
        }
        else if(guess(mid)==-1){
            binarySearch(s, mid-1, ans);
        }
        else if(guess(mid)==1){
            binarySearch(mid+1, e, ans);
        }
    }
    
    int guessNumber(int n) {
        int ans = 0;
        binarySearch(1, n, ans);
        return ans;
    }
};