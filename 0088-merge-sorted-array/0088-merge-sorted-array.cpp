class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // if(n==0){
        //     return;
        // }
        // int i = 0;
        // int j = 0;
        // while(i<m && j<n){
        //     if(nums1[i]<=nums2[j]){
        //         i++; 
        //     }
        //     else{
        //         swap(nums1[i], nums2[j]);
        //         // j++;
        //     }
        // }
        // sort(nums2.begin(), nums2.end());
        // for(int i=m; i<nums1.size(); i++){
        //     swap(nums1[i], nums2[i-m]);
        // }
        for(int i=m; i<nums1.size(); i++){
            swap(nums1[i], nums2[i-m]);
        }
        sort(nums1.begin(), nums1.end());
    }
};